#include <iostream>
#include <fstream>
#include <vector>
#include "Txt.h"

namespace l1
{
	Txt::Txt() = default;
	
	Txt::~Txt()noexcept
	{
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}
	}

	Txt::Txt(const std::string& str)
	{
		std::ifstream file(str);
		if (!file.is_open()) 
		{
			std::cout << "Failed to open file: " + str << std::endl;
		}
		std::vector<std::string> lines;
		std::string line;
		while (std::getline(file, line)) 
		{
			lines.emplace_back(line);
		}
		sizeStr_ = lines.size();
		if (sizeStr_ > 0) 
		{
			data = new std::string[sizeStr_];

			for (size_t i = 0; i < sizeStr_; ++i) 
			{
				data[i] = lines[i];
			}
		}
		file.close();
	}

	Txt::Txt(const Txt& other)
	{
		sizeStr_ = other.sizeStr_;
		if (sizeStr_ > 0) 
		{
			data = new std::string[sizeStr_];

			for (size_t i = 0; i < sizeStr_; ++i) 
			{
				data[i] = other.data[i];
			}
		}
	}

	Txt& Txt::operator=(const Txt& other)
	{
		if (this != &other) 
		{
			delete[] data;
			data = nullptr;
			sizeStr_ = 0;
			if (other.data != nullptr) 
			{
				sizeStr_ = other.sizeStr_;
				data = new std::string[sizeStr_];
				for (size_t i = 0; i < sizeStr_; ++i) 
				{
					data[i] = other.data[i];
				}
			}
		}
		return *this;
	}

	Txt::Txt(Txt&& other) noexcept
	{
		sizeStr_ = other.sizeStr_;
		data = other.data;
		other.sizeStr_ = 0;
		other.data = nullptr;
	}

	Txt& Txt::operator=(Txt&& other) noexcept
	{
		if (this != &other) 
		{
			delete[] data;
			data = nullptr;
			sizeStr_ = 0;
			sizeStr_ = other.sizeStr_;
			data = other.data;
			other.sizeStr_ = 0;
			other.data = nullptr;
		}
		return *this;
	}
}