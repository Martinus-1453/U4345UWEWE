#include "FileWriter.h"

FileWriter::FileWriter()
{
}


FileWriter::~FileWriter()
{
}

void FileWriter::LoadToFile(std::string path, std::vector<std::string> stringVec){
	std::ofstream out;

	out.open(path, std::ios::out);

	if (out.good())
		for (auto i : stringVec)
			out << i << "\n";
	

	out.close();
}