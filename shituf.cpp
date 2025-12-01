
#include <iostream>
#include <windows.h>
using namespace std;
#define FILENAME //enter file path, ex: "C:\\Users\\Amdocs\\Downloads\\operatingsys\\gibrish.bin"
int main()
{
	SYSTEM_INFO sys_info;
	GetSystemInfo(&sys_info);
	int mem_buffer_size = sys_info.dwAllocationGranularity;
	LPCSTR pFileName = FILENAME;
	HANDLE hFile;
	hFile = CreateFileA(
		pFileName, // file name
		GENERIC_ALL, // access type
		FILE_SHARE_READ, // other processes can't share
		NULL, // security
		OPEN_EXISTING, // open only if file exists
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	if (OpenFileMappingA(FILE_MAP_ALL_ACCESS, 0, "myFile"))
	{
		HANDLE hMapFile = CreateFileMappingA(hFile, NULL, PAGE_READWRITE, 0, 0, "myFile");
		DWORD file_size = GetFileSize(hFile, NULL);
		LPSTR pBuf;
		pBuf = (LPSTR)MapViewOfFile(hMapFile, FILE_MAP_READ, 0, 0, mem_buffer_size);
		while (pBuf[0] != '*')
		{
			Sleep(100);
		}
		UnmapViewOfFile(pBuf);
		CloseHandle(hMapFile);
		CloseHandle(hFile);
	}
	else
	{
		HANDLE hmap = CreateFileMappingA(hFile, NULL, PAGE_READWRITE, 0, 0, "myFile");
		if (!hmap)
		{
			cout << GetLastError() << endl;
			return 0;
		}
	}
}