#include "InstructionParser.h"
#include <iostream>
#include <fstream>
#include <filesystem>


class Parser
{
public:
    virtual ~Parser() = default;
    virtual Instruction parse(const std::string &instruction) const = 0;
    virtual const char * get_format() const = 0;
};

class ArifmeticInstructionParser: public Parser
{
    static constexpr char const * HOURS_MINUTES_SECONDS = "^[0-9]{2,19}:[0-9]{2}:[0-9]{2}";

public:
    tecom::qos::ClockDuration parse(const std::string &str) const override
    {
        int timeZoneDifferential;
        auto n = str.find(":");
        auto time =  Poco::DateTimeParser::parse(":%M:%S", str.substr(n), timeZoneDifferential);
        return std::chrono::minutes(time.minute()) +
                std::chrono::seconds(time.second()) +
                std::chrono::hours(boost::lexical_cast<int64_t>(str.substr(0, n)));
    }

    const char * get_format() const override
    {
        return HOURS_MINUTES_SECONDS;
    }
};

class UnSupportedDetector: public Detector
{
    static constexpr char const * UNSUPPORTED = "^.*";

public:
    tecom::qos::ClockDuration parse(const std::string &str) const override
    {
        throw std::runtime_error("Template unsupported");
    }

    const char * get_format() const override
    {
        return UNSUPPORTED;
    }
};

static const std::shared_ptr<Detector>& get_detector(const std::string &str)
{
    static const std::vector<std::shared_ptr<Detector>> detectors = {std::make_shared<HoursMinutesSecondsParser>(),
                                                                 std::make_shared<HoursMinutesSecondsMillisecondsParser>()};

    for(const auto &detector: detectors)
    {
        const std::regex temp_regex(detector->get_format());
        if(std::regex_match(str.data(), temp_regex))
        {
            return detector;
        }
    }
    return detectors.back();
};


InstructionParser::InstructionParser()
{}

InstructionParser::~InstructionParser()
{}

Instructions InstructionParser::parse(const std::string &file)
{
    Instructions result;
    std::filesystem::path file_path{file}; 
    if (std::filesystem::exists(file_path)) 
    {
        if (std::filesystem::is_regular_file(file_path)) 
        {
            std::ifstream file_p{file};
            if (!file_p) 
            {
                throw std::runtime_error("Could not open file: " + file);
            }
            std::string s; 
            while(getline(file_p, s))
            {
                result.push_back(_detector.detect(s));
            } 
        }
    }
    else 
    {
       throw std::runtime_error("File does not exist " + file);
    }
    return {};
}

