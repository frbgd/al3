#include <cassert>
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>
#include <iterator>

namespace fs = std::filesystem;

int main()
{
	fs::create_directories("data/a/b.txt");
	std::vector<fs::path> paths = {
		"data/a/b.txt/1.txt",
		"data/a/b.txt/2.txt",
		"data/a/3.dat",
		"data/4.dat"
	};
	for (const auto& filepath : paths)
	{
		// В C++17 конструктор fstream принимает как string, так и wstring,
		//  это упрощает кроссплатформенное конструирование его из path
		std::ofstream(filepath.native()) << "test";
	}


	{

		fs::recursive_directory_iterator begin("data");
		fs::recursive_directory_iterator end;
		// Получаем список подкаталогов с помощью алгоритма copy_if
		std::vector<fs::path> subdirs;
		std::copy_if(begin, end, std::back_inserter(subdirs), [](const fs::path & path) {
			return fs::is_directory(path);
			});
		// Выводим список подкаталогов в cout.
		std::cout << "-- subdirs --" << std::endl;
		std::copy(subdirs.begin(), subdirs.end(), std::ostream_iterator<fs::path>(std::cout, "\n"));
	}

	{
		fs::recursive_directory_iterator begin("data");
		fs::recursive_directory_iterator end;

		// Получаем список файлов .txt с помощью алгоритма copy_if
		std::vector<fs::path> txtFiles;
		std::copy_if(begin, end, std::back_inserter(txtFiles), [](const fs::path & path) {
			return fs::is_regular_file(path) && (path.extension() == ".txt");
			});
		// Выводим список файлов в cout.
		std::cout << "-- txt files --" << std::endl;
		std::copy(txtFiles.begin(), txtFiles.end(), std::ostream_iterator<fs::path>(std::cout, "\n"));
	}

	//////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Создаём файл и записываем "test!"
	fs::path filepath = fs::current_path() / "example.bin";
	std::ofstream(filepath) << "test!";

	// Размер файла должен быть равен 4
	std:: cout << fs::file_size(filepath) << std::endl;
	fs::remove(filepath);

	// Попытка получить размер несуществующего файла
	try
	{
		fs::file_size(filepath);
	}
	catch (fs::filesystem_error & e)
	{
		std::cout << e.what() << '\n';
	}

	// Версия с error_code возвращает std::uintmax_t(-1)
	std::error_code code;
	std::uintmax_t size = fs::file_size(filepath, code);
	// code содержит объект ошибки
	assert(bool(code) == true);
	// size равен числу -1, приведённому к беззнаковому типу std::uintmax_t
	assert(size == std::uintmax_t(-1));

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////

	 // На Windows может быть выброшено исключение,
	//  т.к. у обычного пользователя нет прав создавать symlink.
	try
	{
		// Записываем файл data/1.dat
		fs::path datPath = "data/1.dat";
		fs::create_directories(datPath.parent_path());
		std::ofstream(datPath.native()) << "testdata";

		// Создаём символическую ссылку data/1.softlink
		fs::path linkPath = "data/1.softlink";
		fs::create_symlink(fs::absolute(datPath), linkPath);

		// Можно определить, является ли объект с заданным путём символической ссылкой.
		assert(!fs::is_symlink(datPath));
		assert(fs::is_symlink(linkPath));

		// Цель ссылки - data/1.dat
		fs::path linkTarget = read_symlink(linkPath);
		assert(fs::read_symlink(linkPath) == fs::absolute(datPath));
	}
	catch (const std::exception & ex)
	{
		std::cerr << "fatal error: " << ex.what() << std::endl;
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////

	fs::space_info currentVolumeSpace = fs::space(".");

	std::cout << std::setw(15) << "Capacity"
		<< std::setw(15) << "Free"
		<< std::setw(15) << "Available"
		<< "\n"
		<< std::setw(15) << currentVolumeSpace.capacity
		<< std::setw(15) << currentVolumeSpace.free
		<< std::setw(15) << currentVolumeSpace.available
		<< "\n";

	return 0;
}