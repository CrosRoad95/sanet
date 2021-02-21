#pragma once

class CConfig : public CSingleton<CConfig>
{
	bool isDebug;

	std::string nickname;
	std::string lang;
	std::wstring gamePath;

public:
	CConfig() :
		isDebug(false),
		nickname("Player"),
		lang("en")
	{

	}

	bool Load(const std::wstring& fileName)
	{
		using json = nlohmann::json;
		json config;

		try
		{
			std::ifstream ifile(fileName);
			ifile >> config;
		}
		catch (json::parse_error)
		{
			return false;
		}

		std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

		try
		{
			nickname = config["nickname"].get<std::string>();
			isDebug = config["debug"].get<bool>();
			lang = config["language"].get<std::string>();
			gamePath = converter.from_bytes(config["game_path"].get<std::string>());
		}
		catch (json::parse_error)
		{
			return false;
		}

		return true;
	}

	bool Save(const std::wstring& filename)
	{
		using json = nlohmann::json;
		json config;

		std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

		config["nickname"] = nickname;
		config["debug"] = isDebug;
		config["language"] = lang;
		config["game_path"] = converter.to_bytes(gamePath);


		std::ofstream ofile(filename);
		ofile << std::setw(4) << config << std::endl;

		return true;
	}

	inline const std::wstring& GetPath() { return gamePath; }
	inline void SetPath(const std::wstring& path) { gamePath = path; }
};
