﻿#ifndef HOLISTIC_TRACKING_API_H
#define HOLISTIC_TRACKING_API_H

#define EXPORT

/* 定义动态链接库dll的导出 */
#include <malloc.h>
#ifdef _WIN32
#ifdef EXPORT
#define EXPORT_API __declspec(dllexport)
#else
#define EXPORT_API __declspec(dllimport)
#endif
#else
#include <stdlib.h>

#ifdef EXPORT
#define EXPORT_API __attribute__((visibility ("default")))
#else
#endif

#endif


#ifdef __cplusplus
extern "C" {
#endif 

#ifndef EXPORT_API
#define EXPORT_API
#endif

	/*
	@brief 初始化Google Mediapipe
	@param[in] model_path 需要加载的模型路径
	@param[in] is_need_video_outputstream 是否在Graph中添加视频输出流
	@param[in] is_need_pose_outputstream 是否在Graph中添加pose输出流
	@param[in] is_need_hand_outputstream 是否在Graph中添加hand输出流
	@param[in] is_need_face_outputstream 是否在Graph中添加face输出流
	@return 返回操作成功或者失败
		0 失败
		1 成功
	*/
	EXPORT_API int MediapipeHolisticTrackingInit(
		const char* model_path,
		bool is_need_video_outputstream = true,
		bool is_need_pose_outputstream = true,
		bool is_need_hand_outputstream = true,
		bool is_need_face_outputstream = true);

	/*
	@brief 检测视频帧
	@param[in] image_width 视频帧宽度
	@param[in] image_height 视频帧高度
	@param[in] image_data 视频帧数据
	@param[in] show_result_image 是否显示结果图片
	@param[out] gesture_result - 手势识别结果
	@return 返回操作成功或者失败
		0 失败
		1 成功
	*/
	EXPORT_API int MediapipeHolisticTrackingDetectFrameDirect(int image_width, int image_height, void* image_data, int* detect_result, bool show_result_image = false);

	/*
	@brief 检测摄像头
	@param[in] show_image 是否显示结果图片
	@return 返回操作成功或者失败
	0 失败
	1 成功
	*/
	EXPORT_API int MediapipeHolisticTrackingDetectCamera(bool show_image = false);
	/*
	@brief Google Mediapipe释放
	@return 返回操作成功或者失败
		0 失败
		1 成功
	*/
	EXPORT_API int MediapipeHolisticTrackingRelease();


	/*
	@brief 检测视频帧
	@param[in] image_width 视频帧宽度
	@param[in] image_height 视频帧高度
	@param[in] image_data 视频帧数据
	@param[int] type 视频帧类型
	@param[out] detect_result 检测结果
	@param[out] detect_result_data - 识别结果

	*/
	EXPORT_API int MediapipeHolisticTrackingDetectFrame(int image_width, int image_height, int type,void* image_data, int* detect_result,void* detect_result_data);


#ifdef __cplusplus
}
#endif 

#endif // !HOLISTIC_TRACKING_API_H
