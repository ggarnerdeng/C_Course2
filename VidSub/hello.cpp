#include "curl_easy.h"
#include "curl_form.h"
#include "curl_ios.h"
#include "curl_exception.h"

std::stringstream get_response(std::string_view url)
{
   std::stringstream str;
   try
   {
      curl::curl_ios<std::stringstream> writer(str);
      curl::curl_easy easy(writer);

      easy.add<CURLOPT_URL>(url.data());
      easy.add<CURLOPT_FOLLOWLOCATION>(1L);

      easy.perform();
   }
   catch (curl::curl_easy_exception const & error)
   {
      auto errors = error.get_traceback();
      error.print_traceback();
   }

   return str;
}

int main()
{
   using namespace std::string_literals;

   auto appid = "0c7978..."s;
   auto location = "Timisoara"s;
   auto url = "https://api.openweathermap.org/data/2.5/weather?q=" + location + "&appid=" + appid;

   auto json = get_response(url);

   std::cout << json.str() << std::endl;

   return 0;
}