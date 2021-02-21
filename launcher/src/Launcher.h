#pragma once

extern std::wstring gtadrm;
extern int gtaversion;
extern bool supported;
extern std::wstring gtapath;

static std::vector<std::pair<int, std::wstring>> supportedVersions = 
{
	{ 1180, L"Other" },
	{ 1290, L"Social Club" },
	{ 1365, L"Social Club" },
	{ 1365, L"Steam" }
};

static std::vector<std::wstring> requiredFiles = 
{
<<<<<<< HEAD
	L"client.dll",
	L"vorbisfile.dll"
=======
	L"libs\\client.dll",
	L"libs\\openLA.dll",
	L"libs\\minidump.dll",
#ifdef _DEBUG
	L"libs\\windowed.dll",
#endif
	L"res\\custom.txd",
>>>>>>> 31dbb5c74b29a47df4cf41280887a66794fdc5ff
};