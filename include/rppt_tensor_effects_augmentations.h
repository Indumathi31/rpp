/*
Copyright (c) 2019 - 2022 Advanced Micro Devices, Inc. All rights reserved.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#ifndef RPPT_TENSOR_EFFECTS_AUGMENTATIONS_H
#define RPPT_TENSOR_EFFECTS_AUGMENTATIONS_H
#include "rpp.h"
#include "rppdefs.h"
#ifdef __cplusplus
extern "C" {
#endif

/******************** gridmask ********************/

// Gridmask augmentation for a NCHW/NHWC layout tensor

// *param[in] srcPtr source tensor memory
// *param[in] srcDesc source tensor descriptor
// *param[out] dstPtr destination tensor memory
// *param[in] dstDesc destination tensor descriptor
// *param[in] tileWidth tileWidth value for gridmask calculation = width of black square + width of spacing until next black square on grid (a single Rpp32u number with tileWidth <= min(srcDescPtr->w, srcDescPtr->h) that applies to all images in the batch)
// *param[in] gridRatio gridRatio value for gridmask calculation = black square width / tileWidth (a single Rpp32f number with 0 <= gridRatio <= 1 that applies to all images in the batch)
// *param[in] gridAngle gridAngle value for gridmask calculation = grid rotation angle in radians (a single Rpp32f number that applies to all images in the batch)
// *param[in] translateVector translateVector for gridmask calculation = grid X and Y translation lengths in pixels (a single RpptUintVector2D x,y value pair that applies to all images in the batch)
// *param[in] roiTensorSrc ROI data for each image in source tensor (2D tensor of size batchSize * 4, in either format - XYWH(xy.x, xy.y, roiWidth, roiHeight) or LTRB(lt.x, lt.y, rb.x, rb.y))
// *param[in] roiType ROI type used (RpptRoiType::XYWH or RpptRoiType::LTRB)
// *returns a  RppStatus enumeration.
// *retval RPP_SUCCESS : succesful completion
// *retval RPP_ERROR : Error

RppStatus rppt_gridmask_gpu(RppPtr_t srcPtr, RpptDescPtr srcDescPtr, RppPtr_t dstPtr, RpptDescPtr dstDescPtr, Rpp32u tileWidth, Rpp32f gridRatio, Rpp32f gridAngle, RpptUintVector2D translateVector, RpptROIPtr roiTensorPtrSrc, RpptRoiType roiType, rppHandle_t rppHandle);
RppStatus rppt_gridmask_host(RppPtr_t srcPtr, RpptDescPtr srcDescPtr, RppPtr_t dstPtr, RpptDescPtr dstDescPtr, Rpp32u tileWidth, Rpp32f gridRatio, Rpp32f gridAngle, RpptUintVector2D translateVector, RpptROIPtr roiTensorPtrSrc, RpptRoiType roiType, rppHandle_t rppHandle);

/******************** spatter ********************/

// Spatter augmentation for a NCHW/NHWC layout tensor

// *param[in] srcPtr source tensor memory
// *param[in] srcDesc source tensor descriptor (srcDescPtr->w must be a maximum of 1920, srcDescPtr->h must be a maximum of 1080)
// *param[out] dstPtr destination tensor memory
// *param[in] dstDesc destination tensor descriptor
// *param[in] spatterColor RGB values to use for the spatter augmentation (A single set of 3 Rpp8u values as RpptRGB that applies to all images in the batch)
// *param[in] roiTensorSrc ROI data for each image in source tensor (2D tensor of size batchSize * 4, in either format - XYWH(xy.x, xy.y, roiWidth, roiHeight) or LTRB(lt.x, lt.y, rb.x, rb.y))
// *param[in] roiType ROI type used (RpptRoiType::XYWH or RpptRoiType::LTRB)
// *returns a  RppStatus enumeration.
// *retval RPP_SUCCESS : succesful completion
// *retval RPP_ERROR : Error

RppStatus rppt_spatter_gpu(RppPtr_t srcPtr, RpptDescPtr srcDescPtr, RppPtr_t dstPtr, RpptDescPtr dstDescPtr, RpptRGB spatterColor, RpptROIPtr roiTensorPtrSrc, RpptRoiType roiType, rppHandle_t rppHandle);
RppStatus rppt_spatter_host(RppPtr_t srcPtr, RpptDescPtr srcDescPtr, RppPtr_t dstPtr, RpptDescPtr dstDescPtr, RpptRGB spatterColor, RpptROIPtr roiTensorPtrSrc, RpptRoiType roiType, rppHandle_t rppHandle);

#ifdef __cplusplus
}
#endif
#endif // RPPT_TENSOR_EFFECTS_AUGMENTATIONS_H
