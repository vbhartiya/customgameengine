#pragma once

#include <sstream>
#include <string>
#include <vector>

namespace engine {
	class StringUtil {
	public:
		static std::vector<std::string> SplitString(std::string input, char delimiter) {
			std::vector<std::string> result;
			std::stringstream ss(input);
			std::string item;
			while (std::getline(ss, item, delimiter)) {
				result.push_back(item);
			}


			return result;
		}
	};
}