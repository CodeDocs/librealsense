// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2015 Intel Corporation. All Rights Reserved.

#include "types.h"
#include "image.h"
#include "device.h"

#include <cstring>
#include <algorithm>
#include <array>
#include <deque>

const char * unknown = "UNKNOWN";

namespace rsimpl
{
    const char * get_string(rs_stream value)
    {
        #define CASE(X) case RS_STREAM_##X: return #X;
        switch(value)
        {
        CASE(DEPTH)
        CASE(COLOR)
        CASE(INFRARED)
        CASE(INFRARED2)
        CASE(POINTS)
        CASE(RECTIFIED_COLOR)
        CASE(COLOR_ALIGNED_TO_DEPTH)
        CASE(DEPTH_ALIGNED_TO_COLOR)
        CASE(DEPTH_ALIGNED_TO_RECTIFIED_COLOR)
        CASE(INFRARED2_ALIGNED_TO_DEPTH)
        CASE(DEPTH_ALIGNED_TO_INFRARED2)
        CASE(FISHEYE)
        default: assert(!is_valid(value)); return unknown;
        }
        #undef CASE
    }

    const char * get_string(rs_format value)
    {
        #define CASE(X) case RS_FORMAT_##X: return #X;
        switch(value)
        {
        CASE(ANY)
        CASE(Z16)
        CASE(DISPARITY16)
        CASE(XYZ32F)
        CASE(YUYV)
        CASE(RGB8)
        CASE(BGR8)
        CASE(RGBA8)
        CASE(BGRA8)
        CASE(Y8)
        CASE(Y16)
        CASE(RAW10)
        CASE(RAW16)
        CASE(RAW8)
		default: assert(!is_valid(value)); return unknown;
        }
        #undef CASE
    }

    const char * get_string(rs_preset value)
    {
        #define CASE(X) case RS_PRESET_##X: return #X;
        switch(value)
        {
        CASE(BEST_QUALITY)
        CASE(LARGEST_IMAGE)
        CASE(HIGHEST_FRAMERATE)
		default: assert(!is_valid(value)); return unknown;
        }
        #undef CASE
    }

    const char * get_string(rs_distortion value)
    {
        #define CASE(X) case RS_DISTORTION_##X: return #X;
        switch(value)
        {
        CASE(NONE)
        CASE(MODIFIED_BROWN_CONRADY)
        CASE(INVERSE_BROWN_CONRADY)
		default: assert(!is_valid(value)); return unknown;
        }
        #undef CASE
    }

    const char * get_string(rs_option value)
    {
        #define CASE(X) case RS_OPTION_##X: return #X;
        switch(value)
        {
        CASE(COLOR_BACKLIGHT_COMPENSATION)
        CASE(COLOR_BRIGHTNESS)
        CASE(COLOR_CONTRAST)
        CASE(COLOR_EXPOSURE)
        CASE(COLOR_GAIN)
        CASE(COLOR_GAMMA)
        CASE(COLOR_HUE)
        CASE(COLOR_SATURATION)
        CASE(COLOR_SHARPNESS)
        CASE(COLOR_WHITE_BALANCE)
        CASE(COLOR_ENABLE_AUTO_EXPOSURE)
        CASE(COLOR_ENABLE_AUTO_WHITE_BALANCE)
        CASE(F200_LASER_POWER)
        CASE(F200_ACCURACY)
        CASE(F200_MOTION_RANGE)
        CASE(F200_FILTER_OPTION)
        CASE(F200_CONFIDENCE_THRESHOLD)
        CASE(F200_DYNAMIC_FPS)
        CASE(SR300_AUTO_RANGE_ENABLE_MOTION_VERSUS_RANGE) 
        CASE(SR300_AUTO_RANGE_ENABLE_LASER)               
        CASE(SR300_AUTO_RANGE_MIN_MOTION_VERSUS_RANGE)    
        CASE(SR300_AUTO_RANGE_MAX_MOTION_VERSUS_RANGE)    
        CASE(SR300_AUTO_RANGE_START_MOTION_VERSUS_RANGE)  
        CASE(SR300_AUTO_RANGE_MIN_LASER)                  
        CASE(SR300_AUTO_RANGE_MAX_LASER)                  
        CASE(SR300_AUTO_RANGE_START_LASER)                
        CASE(SR300_AUTO_RANGE_UPPER_THRESHOLD) 
        CASE(SR300_AUTO_RANGE_LOWER_THRESHOLD)
        CASE(SR300_WAKEUP_DEV_PHASE1_PERIOD)
        CASE(SR300_WAKEUP_DEV_PHASE1_FPS)
        CASE(SR300_WAKEUP_DEV_PHASE2_PERIOD)
        CASE(SR300_WAKEUP_DEV_PHASE2_FPS)
        CASE(SR300_WAKEUP_DEV_RESET)
        CASE(SR300_WAKE_ON_USB_REASON)
        CASE(SR300_WAKE_ON_USB_CONFIDENCE)
        CASE(R200_LR_AUTO_EXPOSURE_ENABLED)
        CASE(R200_LR_GAIN)
        CASE(R200_LR_EXPOSURE)
        CASE(R200_EMITTER_ENABLED)
        CASE(R200_DEPTH_UNITS)
        CASE(R200_DEPTH_CLAMP_MIN)
        CASE(R200_DEPTH_CLAMP_MAX)
        CASE(R200_DISPARITY_MULTIPLIER)
        CASE(R200_DISPARITY_SHIFT)
        CASE(R200_AUTO_EXPOSURE_MEAN_INTENSITY_SET_POINT)
        CASE(R200_AUTO_EXPOSURE_BRIGHT_RATIO_SET_POINT)  
        CASE(R200_AUTO_EXPOSURE_KP_GAIN)                 
        CASE(R200_AUTO_EXPOSURE_KP_EXPOSURE)             
        CASE(R200_AUTO_EXPOSURE_KP_DARK_THRESHOLD)       
        CASE(R200_AUTO_EXPOSURE_TOP_EDGE)       
        CASE(R200_AUTO_EXPOSURE_BOTTOM_EDGE)    
        CASE(R200_AUTO_EXPOSURE_LEFT_EDGE)      
        CASE(R200_AUTO_EXPOSURE_RIGHT_EDGE)     
        CASE(R200_DEPTH_CONTROL_ESTIMATE_MEDIAN_DECREMENT)   
        CASE(R200_DEPTH_CONTROL_ESTIMATE_MEDIAN_INCREMENT)   
        CASE(R200_DEPTH_CONTROL_MEDIAN_THRESHOLD)            
        CASE(R200_DEPTH_CONTROL_SCORE_MINIMUM_THRESHOLD)     
        CASE(R200_DEPTH_CONTROL_SCORE_MAXIMUM_THRESHOLD)     
        CASE(R200_DEPTH_CONTROL_TEXTURE_COUNT_THRESHOLD)     
        CASE(R200_DEPTH_CONTROL_TEXTURE_DIFFERENCE_THRESHOLD)
        CASE(R200_DEPTH_CONTROL_SECOND_PEAK_THRESHOLD)       
        CASE(R200_DEPTH_CONTROL_NEIGHBOR_THRESHOLD)
        CASE(R200_DEPTH_CONTROL_LR_THRESHOLD)
        CASE(ZR300_GYRO_BANDWIDTH)
        CASE(ZR300_GYRO_RANGE)
        CASE(ZR300_ACCELEROMETER_BANDWIDTH)
        CASE(ZR300_ACCELEROMETER_RANGE)
        CASE(ZR300_MOTION_MODULE_TIME_SEED)
        CASE(ZR300_MOTION_MODULE_ACTIVE)
        CASE(FISHEYE_COLOR_EXPOSURE)
        CASE(FISHEYE_COLOR_GAIN)
        CASE(FISHEYE_STROBE)
        CASE(FISHEYE_EXT_TRIG)
		default: assert(!is_valid(value)); return unknown;
        }
        #undef CASE
    }

    const char * get_string(rs_source value)
    {
        #define CASE(X) case RS_SOURCE_##X: return #X;
        switch(value)
        {
        CASE(VIDEO)
        CASE(MOTION_TRACKING)
        CASE(ALL)
		default: assert(!is_valid(value)); return unknown;
        }
        #undef CASE
    }
    
    const char * get_string(rs_capabilities value)
    {
        #define CASE(X) case RS_CAPABILITIES_##X: return #X;
        switch(value)
        {
        CASE(DEPTH)
        CASE(COLOR)
        CASE(INFRARED)
        CASE(INFRARED2)
        CASE(FISH_EYE)
        CASE(MOTION_EVENTS)
		default: assert(!is_valid(value)); return unknown;
        }
        #undef CASE
    }

    const char * get_string(rs_event_source value)
    {
        #define CASE(X) case RS_EVENT_##X: return #X;
        switch(value)
        {
        CASE(IMU_ACCEL)
        CASE(IMU_GYRO)
        CASE(IMU_DEPTH_CAM)
        CASE(IMU_MOTION_CAM)
        CASE(G0_SYNC)
        CASE(G1_SYNC)
        CASE(G2_SYNC)
		default: assert(!is_valid(value)); return unknown;
        }
        #undef CASE
    }

    size_t subdevice_mode_selection::get_image_size(rs_stream stream) const
    {
        return rsimpl::get_image_size(get_width(), get_height(), get_format(stream));
    }

    void subdevice_mode_selection::set_output_buffer_format(const rs_output_buffer_format in_output_format)
    {
        output_format = in_output_format;
    }

    void subdevice_mode_selection::unpack(byte * const dest[], const byte * source) const
    {
        const int MAX_OUTPUTS = 2;
        const auto & outputs = get_outputs();        
        assert(outputs.size() <= MAX_OUTPUTS);

        // Determine input stride (and apply cropping)
        const byte * in = source;
        size_t in_stride = mode.pf.get_image_size(mode.native_dims.x, 1);
        if(pad_crop < 0) in += in_stride * -pad_crop + mode.pf.get_image_size(-pad_crop, 1);

        // Determine output stride (and apply padding)
        byte * out[MAX_OUTPUTS];
        size_t out_stride[MAX_OUTPUTS] = { 0 };
        for(size_t i=0; i<outputs.size(); ++i)
        {
            out[i] = dest[i];
            out_stride[i] = rsimpl::get_image_size(get_width(), 1, outputs[i].second);
            if(pad_crop > 0) out[i] += out_stride[i] * pad_crop + rsimpl::get_image_size(pad_crop, 1, outputs[i].second);
        }

        // Unpack (potentially a subrect of) the source image into (potentially a subrect of) the destination buffers
        const int unpack_width = get_unpacked_width(), unpack_height = get_unpacked_height();
        if(mode.native_dims.x == get_width())
        {
            // If not strided, unpack as though it were a single long row
            mode.pf.unpackers[unpacker_index].unpack(out, in, unpack_width * unpack_height);
        }
        else
        {
            // Otherwise unpack one row at a time
            assert(mode.pf.plane_count == 1); // Can't unpack planar formats row-by-row (at least not with the current architecture, would need to pass multiple source ptrs to unpack)
            for(int i=0; i<unpack_height; ++i)
            {
                mode.pf.unpackers[unpacker_index].unpack(out, in, unpack_width);
                for(size_t i=0; i<outputs.size(); ++i) out[i] += out_stride[i];
                in += in_stride;
            }
        }
    }

    int subdevice_mode_selection::get_unpacked_width() const
    {
        return std::min(mode.native_intrinsics.width, get_width());
    }

    int subdevice_mode_selection::get_unpacked_height() const
    {
        return std::min(mode.native_intrinsics.height, get_height());
    }

    ////////////////////////
    // static_device_info //
    ////////////////////////

    bool stream_request::contradict(stream_request req) const
    {
        if (((format != RS_FORMAT_ANY && format != req.format) ||
            (width != 0 && width != req.width) ||
            (height != 0 && height != req.height) ||
            (fps != 0 && fps != req.fps) ||
            (output_format != req.output_format)))
            return true;
        return false;
    }

    static_device_info::static_device_info()
    {
        for(auto & s : stream_subdevices) s = -1;
        for(auto & s : data_subdevices) s = -1;
        for(auto & s : presets) for(auto & p : s) p = stream_request();
        for(auto & p : stream_poses)
        {
            p = {{{1,0,0},{0,1,0},{0,0,1}}, {0,0,0}};
        }
    }


    struct params
    {
        stream_request requests[RS_STREAM_NATIVE_COUNT];
        int stream;
        params(stream_request in_requests[RS_STREAM_NATIVE_COUNT], int i):
            
            stream(i)
        {
            for (auto i = 0; i<RS_STREAM_NATIVE_COUNT; i++)
            {
                requests[i] = in_requests[i];
            }
        }
    };

    bool device_config::all_requests_filled(const stream_request(&requests)[RS_STREAM_NATIVE_COUNT]) const
    {
        for (auto i = 0; i<RS_STREAM_NATIVE_COUNT; i++)
        {
            if (requests[i].enabled &&
                (requests[i].height == 0 ||
                requests[i].width == 0 ||
                requests[i].format == RS_FORMAT_ANY ||
                requests[i].fps == 0))
                return false;
        }
        return true;
    }

    bool device_config::find_good_requests_combination( stream_request(&requests)[RS_STREAM_NATIVE_COUNT], std::vector<stream_request> stream_requests[RS_STREAM_NATIVE_COUNT]) const
    {
        std::deque<params> calls;
  
        params p = { requests, 0 };

        calls.push_back(p);

        while (!calls.empty())
        {
            p = calls.back();
            calls.pop_back();

            if (all_requests_filled(p.requests) && validate_requests(p.requests))
            {
                for (auto i = 0; i < RS_STREAM_NATIVE_COUNT; i++)
                {
                    requests[i] = p.requests[i];
                }
                return true;
            }

            for (auto i = 0; i < stream_requests[p.stream].size(); i++)
            {
                if (!requests[p.stream].enabled) break;

                if (!requests[p.stream].contradict(stream_requests[p.stream][i]))
                {
                    p.requests[p.stream] = stream_requests[p.stream][i];

                    if (validate_requests(p.requests))
                    { 
                        params new_p = { p.requests, p.stream + 1 };
                        calls.push_back(new_p);
                    }
                }
            }

        }
        return false;

  
    }

    bool device_config::fill_requests(stream_request(&requests)[RS_STREAM_NATIVE_COUNT]) const
    {
        // Determine if the user has requested any streams which are supplied by this subdevice
        
        if(all_requests_filled(requests))
        {
            return true;
        }

        std::vector<stream_request> stream_requests[RS_STREAM_NATIVE_COUNT];
        get_all_possible_requestes(stream_requests);

        return find_good_requests_combination(requests, stream_requests);
    }

    void device_config::get_all_possible_requestes(std::vector<stream_request>(&stream_requests)[RS_STREAM_NATIVE_COUNT]) const
    {
        for (auto i = 0; i < info.subdevice_modes.size(); i++)
        {
            stream_request request;
            auto mode = info.subdevice_modes[i];

            for (auto pad_crop : mode.pad_crop_options)
            {
                for (auto & unpacker : mode.pf.unpackers)
                {
                    auto selection = subdevice_mode_selection(mode, pad_crop, &unpacker - mode.pf.unpackers.data());

                    request.enabled = true;
                    request.fps = selection.get_framerate();
                    request.height = selection.get_height();
                    request.width = selection.get_width();
                    auto outputs = selection.get_outputs();

                    for (auto output : outputs)
                    {
                        request.format = output.second;
                        for (auto output_format = static_cast<int>(RS_OUTPUT_BUFFER_FORMAT_CONTINOUS); output_format < static_cast<int>(RS_OUTPUT_BUFFER_FORMAT_COUNT); output_format++)
                        {
                            request.output_format = static_cast<rs_output_buffer_format>(output_format);
                            stream_requests[output.first].push_back(request);
                            if (output.first == rs_stream::RS_STREAM_COLOR)
                            {
                                request.format = output.second;;
                            }
                        }

                    }
                }
            }
        }
    }

    subdevice_mode_selection device_config::select_mode(const  stream_request(&requests)[RS_STREAM_NATIVE_COUNT], int subdevice_index) const
    {
        // Determine if the user has requested any streams which are supplied by this subdevice
        auto any_stream_requested = false;
        std::array<bool, RS_STREAM_NATIVE_COUNT> stream_requested = {};
        for(int j = 0; j < RS_STREAM_NATIVE_COUNT; ++j)
        {
            if(requests[j].enabled && info.stream_subdevices[j] == subdevice_index)
            {
                stream_requested[j] = true;
                any_stream_requested = true;
            }
        }

        // If no streams were requested, skip to the next subdevice
        if(!any_stream_requested) return subdevice_mode_selection();

        // Look for an appropriate mode
        for(auto & subdevice_mode : info.subdevice_modes)
        {
            // Skip modes that apply to other subdevices
            if(subdevice_mode.subdevice != subdevice_index) continue;

            for(auto pad_crop : subdevice_mode.pad_crop_options)
            {
                for(auto & unpacker : subdevice_mode.pf.unpackers)
                {
                    auto selection = subdevice_mode_selection(subdevice_mode, pad_crop, (int)(&unpacker - subdevice_mode.pf.unpackers.data()));

                    // Determine if this mode satisfies the requirements on our requested streams
                    auto stream_unsatisfied = stream_requested;
                    for(auto & output : unpacker.outputs)
                    {
                        const auto & req = requests[output.first];
                        
                        selection.set_output_buffer_format(req.output_format);
                        if(req.enabled && (req.width == selection.get_width() )
                                       && (req.height == selection.get_height())
                                       && (req.format == selection.get_format(output.first))
                                       && (req.fps == subdevice_mode.fps))
                        {
                            stream_unsatisfied[output.first] = false;
                        }
                    }

                    // If any requested streams are still unsatisfied, skip to the next mode
                    if(std::any_of(begin(stream_unsatisfied), end(stream_unsatisfied), [](bool b) { return b; })) continue;
                    return selection;
                }
            }
        }

        // If we did not find an appropriate mode, report an error
        std::ostringstream ss;
        ss << "uvc subdevice " << subdevice_index << " cannot provide";
        bool first = true;
        for(int j = 0; j < RS_STREAM_NATIVE_COUNT; ++j)
        {
            if(!stream_requested[j]) continue;
            ss << (first ? " " : " and ");
            ss << requests[j].width << 'x' << requests[j].height << ':' << get_string(requests[j].format);
            ss << '@' << requests[j].fps << "Hz " << get_string((rs_stream)j);
            first = false;
        }
        throw std::runtime_error(ss.str());
    }

    std::vector<subdevice_mode_selection> device_config::select_modes(const stream_request (&reqs)[RS_STREAM_NATIVE_COUNT]) const
    {
        // Make a mutable copy of our array
        stream_request requests[RS_STREAM_NATIVE_COUNT];
        for (int i = 0; i<RS_STREAM_NATIVE_COUNT; ++i) requests[i] = reqs[i];

        validate_requests(requests, true);

        fill_requests(requests);

        // Select subdevice modes needed to satisfy our requests
        int num_subdevices = 0;
        for(auto & mode : info.subdevice_modes) num_subdevices = std::max(num_subdevices, mode.subdevice+1);
        std::vector<subdevice_mode_selection> selected_modes;
        for(int i = 0; i < num_subdevices; ++i)
        {
            auto selection = select_mode(requests, i);
            if(selection.mode.pf.fourcc) selected_modes.push_back(selection);
        }
        return selected_modes;
    }

    bool device_config::validate_requests(stream_request(&requests)[RS_STREAM_NATIVE_COUNT], bool throw_exception) const
    {
        // Check and modify requests to enforce all interstream constraints

        for (auto & rule : info.interstream_rules)
        {
            auto & a = requests[rule.a], &b = requests[rule.b]; auto f = rule.field;
            if (a.enabled && b.enabled)
            {
                if (rule.bigger == RS_STREAM_COUNT && !rule.diveded && !rule.diveded2)
                {
                    // Check for incompatibility if both values specified
                    if (a.*f != 0 && b.*f != 0 && a.*f + rule.delta != b.*f && a.*f + rule.delta2 != b.*f)
                    {
                        if (throw_exception)
                            throw std::runtime_error(to_string() << "requested " << rule.a << " and " << rule.b << " settings are incompatible");
                        return false;
                    }
                }
                else
                {
                    if (a.*f != 0 && b.*f != 0 && (rule.bigger == rule.a && a.*f < b.*f) || (rule.bigger == rule.b && b.*f < a.*f))
                    {
                        if (throw_exception)
                            throw std::runtime_error(to_string() << "requested " << rule.a << " and " << rule.b << " settings are incompatible");
                        return false;
                    }
                    if (a.*f != 0 && b.*f != 0 && ((rule.diveded && float(a.*f) / float(b.*f) - a.*f / b.*f > 0) || (rule.diveded2 && float(b.*f) / float(a.*f) - b.*f / a.*f > 0)))
					{
						rs_stream bigger;
                        if (throw_exception)
                            throw std::runtime_error(to_string() << "requested " << rule.a << " and " << rule.b << " settings are incompatible");
                        return false;
                    }
                }
            }
        }
        return true;
    }
}
