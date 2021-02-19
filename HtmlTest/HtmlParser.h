#include <iostream>
#include "Util/StringUtils.h"
#include <cstring>

enum class eHtmlType
{
	GET
};

enum class ePageType
{
	HTML,
	CSS,
	JS
};

const char DEFALUT_PAGE[] = "/index.html";
struct htmlData
{
	char page[155];
	char http_ver[80];
	char type[20];
	ePageType page_type;
	
};

class HtmlParser
{
	public:
	HtmlParser();
	
	void Parse(const char* buf);
	struct htmlData data;
	
};

HtmlParser::HtmlParser()
{
	memset(&data, 0, sizeof(data));
}


void HtmlParser::Parse(const char* buf)
{
	
	char *tr;
	char token[] = " ";
	int i;

	int cis = StringUtil::getCharIndex(buf, ' ', 0);
	int cie = StringUtil::getCharIndex(buf, ' ', cis+1);
	
	
	StringUtil::copyStr(buf, data.type, 0,cis);
	
	
	if(cie-cis-1 == 1)
	{
		StringUtil::copyStr(DEFALUT_PAGE, data.page, 0,sizeof(DEFALUT_PAGE));
	} else {
		StringUtil::copyStr(buf, data.page, cis+1,cie-cis-1);
	}
	
	int comIndex = StringUtil::getCharIndex(data.page, '.', 0);
	
	
	std::cout <<data.page+comIndex << std::endl;
	if(strncmp("html" , data.page+comIndex+1,strlen(data.page+comIndex+1)) == 0)
	{
		data.page_type = ePageType::HTML;
	}
	
	if(strncmp("js" , data.page+comIndex+1,strlen(data.page+comIndex+1)) == 0)
	{
		data.page_type = ePageType::JS;
	}
	
	if(strncmp("css" , data.page+comIndex+1,strlen(data.page+comIndex+1)) == 0)
	{
		data.page_type = ePageType::CSS;
	}
	
}