#include "stdafx.h"
#include <stdint.h>
#include <conio.h>
#include "FileIoHelperClass.h"
#include "StopWatch.h"
#include "mmio.h"


int _tmain(int argc, _TCHAR* argv[])
{
	LARGE_INTEGER fileSize;
	fileSize.QuadPart = 10240000000;
	_ASSERTE(create_very_big_file(L"big.txt", 4));
	StopWatch sw1;
	sw1.Start();
	_ASSERTE(file_copy_using_read_write(L"big.txt", L"big1.txt"));
	sw1.Stop();
	print("info] time elapsed = %f", sw1.GetDurationSecond());
	StopWatch sw2;
	sw2.Start();
	_ASSERTE(file_copy_using_memory_map(L"big.txt", L"big2.txt"));
	sw2.Stop();
	print("info] time elapsed = %f", sw2.GetDurationMilliSecond());
	return 0;
}