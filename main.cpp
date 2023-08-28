#include <iostream>

// 파일 스트림 헤더 파일
#include <fstream>

#include <vector>

class Monster
{
private:
	std::string mName;
	int mLevel;
	int mHP;
	int mMP;

public:
	Monster(std::string name, int level, int hp, int mp) : mName{ name }, mLevel{ level }, mHP{ hp }, mMP{ mp }
	{
	}

	friend std::ostream& operator << (std::ostream& os, Monster m)
	{
		os << m.mName << " : " << m.mLevel << ", " << m.mHP << ", " << m.mMP << std::endl;
		return os;
	}
};


bool LoadFile(const std::string& filename, std::vector<Monster>& monsters)
{
	

	std::ifstream ifs;
	ifs.exceptions(std::ifstream::badbit || std::ifstream::failbit);

	try
	{
		ifs.open(filename);

		char ch;

		while (ifs.get(ch))
		{
			//std::cout << ch;
		}
		ifs.close();
	}

	catch (std::ifstream::failure e)
	{
		std::cerr << std::endl << e.code() << " : " << e.what() << std::endl;
		ifs.close();
		return false;
	}
	
	
	
	//// file stream
	//std::ifstream ifs(filename);

	//// file operation
	//char ch;

	//while (ifs >> ch)
	//{
	//	std::cout << ch;
	//}

	//while (ifs.get(ch))
	//{
	//	std::cout << ch;
	//}
	//while (true)
	//{
	//	ifs.get(ch);

	//	if (ifs.eof())
	//	{
	//		if (ifs.eof())
	//		{
	//			std::cerr << "end of file!!" << std::endl;
	//			break;
	//		}

	//		if (ifs.fail())
	//		{
	//			std::cerr << "logical error!" << std::endl;
	//		}
	//		if (ifs.bad())
	//		{
	//			std::cerr << "fatal error!" << std::endl;
	//		}

	//	}
	//}
	///*char buffer[1024];
	//while(ifs.getline(buffer, 1024))
	//{
	//	std::cout << buffer;
	//}*/


	///*while (true)
	//{
	//	ifs >> ch;
	//	if (ifs.eof())
	//	{
	//		break;
	//	}
	//	std::cout << ch;
	//}*/

	//// close file
	//ifs.close();
	return true;
}

int main()
{
	// 경로 
	//path( directory or folder, file )

	// 절대 경로 표기법
	// LoadFile("C:/Programmer/cpp/FileSystem/Data/SimpleData.txt");

	// 상대 경로 표기법
	// LoadFile("Data/SimpleData.txt");


	std::vector<Monster> monsters;

	LoadFile("Data/SimpleData.txt", monsters);

	for (const auto& e : monsters)
	{
		std::cout << e << std::endl;
	}


}
