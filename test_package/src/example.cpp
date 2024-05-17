#include <vector>
#include <string>

#include "Poco/Logger.h"
#include "Poco/ConsoleChannel.h"
#include "Poco/PatternFormatter.h"
#include "Poco/FormattingChannel.h"

void init_poco_logger()
{
    Poco::AutoPtr<Poco::ConsoleChannel> pCons(new Poco::ConsoleChannel);
    Poco::AutoPtr<Poco::PatternFormatter> pPF(new Poco::PatternFormatter);
    pPF->setProperty("pattern", "%L%H:%M:%S.%i [%I %q %s][%O:%u] %t");
    Poco::AutoPtr<Poco::FormattingChannel> pFC(new Poco::FormattingChannel(pPF, pCons));
    Poco::Logger::root().setChannel(pFC);
    Poco::Logger &logger = Poco::Logger::get("raven");
    logger.setLevel(Poco::Message::PRIO_DEBUG);
}

int main()
{
    init_poco_logger();
    Poco::Logger &logger = Poco::Logger::get("raven");
    logger.debug("Hello, Poco!");
}
