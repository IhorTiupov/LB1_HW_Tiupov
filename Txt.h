#pragma once
#include <string>

namespace l1
{
	class Txt
	{
	public:
		Txt();
		Txt(const std::string& filePath);

		Txt(const Txt& other);
		Txt& operator=(const Txt& other);

		Txt(Txt&& other) noexcept;
		Txt& operator=(Txt&& other) noexcept;

		~Txt()noexcept;

	public:
		inline size_t size() const
		{
			return sizeStr_;
		}

	private:
		size_t sizeStr_ = 0;
		std::string* data = nullptr;
	};
}
