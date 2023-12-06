#pragma once
#include <boost/asio.hpp>
#include <iostream>
#include <chrono>
#include <functional>
#include <deque>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <nlohmann/json.hpp>


//ffmpeg


#include "libavcodec/avcodec.h"
#include "libavfilter/avfilter.h"
#include "libavformat/avformat.h"
#include "libavutil/avutil.h"
#include "libavutil/ffversion.h"
#include "libswresample/swresample.h"
#include "libswscale/swscale.h"
//#include "libpostproc/postprocess.h"


using json = nlohmann::json;
namespace za
{
	namespace net
	{
		//void testJson();
		//void testFFMPEG();
	}
}