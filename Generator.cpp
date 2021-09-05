#include "Generator.h"
#include <string>
#include <vector>


//assigning characters

const std::string Generator::lower{ "qwertyuioplkjhgfdsazxcvbnm" };
const std::string Generator::upper{ "QWERTYUIOPLKJHGFDSAZXCVBNM" };
const std::string Generator::digits{ "1234567890" };
const std::string Generator::special{ "`~!@#$%^&*()-=_+[{]}\\|,<.>/?;:'\"" };
const std::vector<std::string> Generator::arr{ lower,upper,digits,special };