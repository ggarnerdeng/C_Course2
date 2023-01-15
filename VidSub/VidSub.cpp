
#include <iostream>
#include <curl/curl.h>

using namespace std;

int main() {
    string youtubeLink;
    cout << "Enter youtube link: ";
    cin >> youtubeLink;

    string downloadLink = "https://wave.video/convert/youtube-to-mp4?youtube_url=" + youtubeLink + "&resolution=720p";

    CURL* curl;
    FILE* fp;
    CURLcode res;
    char* url = &downloadLink[0u];
    char outfilename[FILENAME_MAX] = "video.mp4";
    curl = curl_easy_init();
    if (curl) {
        fp = fopen(outfilename, "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
    }
    return 0;
}