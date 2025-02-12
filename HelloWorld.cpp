#include<Windows.h>
#include<tchar.h>
#include<stdio.h>
#include<strsafe.h>

#define bufferSize 5
DWORD g_BytesTransferred = 0;

void DisplayError(LPTSTR lpszFunction);

void CALLBACK FileIOCompletionRoutine(
	__in DWORD dwErrorCode,
	__in DWORD dwNumberOfTheBytesTransfered,
	__in LPOVERLAPPED lpOverlapped
);

VOID CALLBACK FileIOCompletionRoutine(
	__in DWORD dwErrorCode,
	__in DWORD dwNumberOfBytesTransfered,
	__in LPOVERLAPPED lpOverlapped
) {
	_tprintf(TEXT("Error code:\t%x\n"), dwErrorCode);
	_tprintf(TEXT("Number of bytes:\t%x\n"), dwNumberOfBytesTransfered);
	g_BytesTransferred = dwNumberOfBytesTransfered;
}

void __cdecl _tmain(int argc, TCHAR *argv[]) {
	HANDLE hFile;
	DWORD dwBytesRead = 0;
	char ReadBuffer[bufferSize] = { 0 };
	OVERLAPPED ol = { 0 };

	printf("\n");
	if (argc != 2) {
		printf("Usage Error: Incorrect number of arguments\n\n");
		_tprintf(TEXT("Usage:\n\t%s test.txt\n"), argv[0]);
		return;
	}

	hFile = CreateFile(argv[1],
		GENERIC_READ,		//open for reading
		FILE_SHARE_READ,	//share for reading
		NULL,				//default security
		OPEN_EXISTING,		//existing file only
		FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, //normal file
		NULL);				//no attribute template

	if (hFile == INVALID_HANDLE_VALUE) {
		DisplayError(TEXT("CreateFile"));
		_tprintf(TEXT("Terminal failure: unable to open file \"%s\" for read.\n"), argv[1]);
		return;
		}

	if (FALSE == ReadFileEx(hFile, ReadBuffer, bufferSize - 1, &ol, FileIOCompletionRoutine)) {
		DisplayError(TEXT("ReadFile"));
		printf("Terminal falure: Unable to read from file. \n Get Last Error=%08x\n", GetLastError());
		CloseHandle(hFile);
		return;
	}
	SleepEx(5000, TRUE);
	dwBytesRead = g_BytesTransferred;

	if (dwBytesRead > 0 && dwBytesRead <= bufferSize - 1) {
		ReadBuffer[dwBytesRead] = '\0';
		_tprintf(TEXT("data read from %s (%d bytes): \n"), argv[1], dwBytesRead);
		printf("%s\n", ReadBuffer);
	}
	else if (dwBytesRead == 0) {
		_tprintf(TEXT("No data read from file %s\n"), argv[1]);
	}
	else {
		printf("\n **Unexpected value for dwBytesRead **\n");
	}
	CloseHandle(hFile);
}

void DisplayError(LPTSTR lpszFunction) {
	LPVOID lpMsgBuf;
	LPVOID lpDisplayBuf;
	DWORD dw = GetLastError();

	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		dw,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf,
		0,
		NULL);

	lpDisplayBuf = (LPVOID)LocalAlloc(LMEM_ZEROINIT,
		(lstrlen((LPCTSTR)lpMsgBuf)
			+ lstrlen((LPCTSTR)lpszFunction)
			+ 40) * sizeof(TCHAR));

	if (FAILED(StringCchPrintf((LPTSTR)lpDisplayBuf,
		LocalSize(lpDisplayBuf) / sizeof(TCHAR),
		TEXT("%s failed with error code %d as follows: \n%s"),
		lpszFunction,
		dw,
		lpMsgBuf)))
	{
		printf("fatal error: unable to output error code.\n");
	}
	_tprintf(TEXT("error: %s\n"), (LPCTSTR)lpDisplayBuf);

	LocalFree(lpMsgBuf);
	LocalFree(lpDisplayBuf);
}