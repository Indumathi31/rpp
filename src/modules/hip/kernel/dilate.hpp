#include <hip/hip_runtime.h>
#include "hip/rpp_hip_common.hpp"

// -------------------- Set 0 - dilate device helpers --------------------

__device__ void dilate_3x3_row_hip_compute(uchar *srcPtr, d_float8 *dst_f8)
{
    float src_f;
    uint3 src_uchar12;
    src_uchar12 = *(uint3 *)srcPtr;
    src_f = rpp_hip_unpack0(src_uchar12.x);
    dst_f8->x.x = fmaxf(src_f, dst_f8->x.x);
    src_f = rpp_hip_unpack1(src_uchar12.x);
    dst_f8->x.x = fmaxf(src_f, dst_f8->x.x);
    dst_f8->x.y = fmaxf(src_f, dst_f8->x.y);
    src_f = rpp_hip_unpack2(src_uchar12.x);
    dst_f8->x.x = fmaxf(src_f, dst_f8->x.x);
    dst_f8->x.y = fmaxf(src_f, dst_f8->x.y);
    dst_f8->x.z = fmaxf(src_f, dst_f8->x.z);
    src_f = rpp_hip_unpack3(src_uchar12.x);
    dst_f8->x.y = fmaxf(src_f, dst_f8->x.y);
    dst_f8->x.z = fmaxf(src_f, dst_f8->x.z);
    dst_f8->x.w = fmaxf(src_f, dst_f8->x.w);
    src_f = rpp_hip_unpack0(src_uchar12.y);
    dst_f8->x.z = fmaxf(src_f, dst_f8->x.z);
    dst_f8->x.w = fmaxf(src_f, dst_f8->x.w);
    dst_f8->y.x = fmaxf(src_f, dst_f8->y.x);
    src_f = rpp_hip_unpack1(src_uchar12.y);
    dst_f8->x.w = fmaxf(src_f, dst_f8->x.w);
    dst_f8->y.x = fmaxf(src_f, dst_f8->y.x);
    dst_f8->y.y = fmaxf(src_f, dst_f8->y.y);
    src_f = rpp_hip_unpack2(src_uchar12.y);
    dst_f8->y.x = fmaxf(src_f, dst_f8->y.x);
    dst_f8->y.y = fmaxf(src_f, dst_f8->y.y);
    dst_f8->y.z = fmaxf(src_f, dst_f8->y.z);
    src_f = rpp_hip_unpack3(src_uchar12.y);
    dst_f8->y.y = fmaxf(src_f, dst_f8->y.y);
    dst_f8->y.z = fmaxf(src_f, dst_f8->y.z);
    dst_f8->y.w = fmaxf(src_f, dst_f8->y.w);
    src_f = rpp_hip_unpack0(src_uchar12.z);
    dst_f8->y.z = fmaxf(src_f, dst_f8->y.z);
    dst_f8->y.w = fmaxf(src_f, dst_f8->y.w);
    src_f = rpp_hip_unpack1(src_uchar12.z);
    dst_f8->y.w = fmaxf(src_f, dst_f8->y.w);
}

__device__ void dilate_5x5_row_hip_compute(uchar *srcPtr, d_float8 *dst_f8)
{
    float src_f;
    uint3 src_uchar12;
    src_uchar12 = *(uint3 *)srcPtr;
    src_f = rpp_hip_unpack0(src_uchar12.x);
    dst_f8->x.x = fmaxf(src_f, dst_f8->x.x);
    src_f = rpp_hip_unpack1(src_uchar12.x);
    dst_f8->x.x = fmaxf(src_f, dst_f8->x.x);
    dst_f8->x.y = fmaxf(src_f, dst_f8->x.y);
    src_f = rpp_hip_unpack2(src_uchar12.x);
    dst_f8->x.x = fmaxf(src_f, dst_f8->x.x);
    dst_f8->x.y = fmaxf(src_f, dst_f8->x.y);
    dst_f8->x.z = fmaxf(src_f, dst_f8->x.z);
    src_f = rpp_hip_unpack3(src_uchar12.x);
    dst_f8->x.x = fmaxf(src_f, dst_f8->x.x);
    dst_f8->x.y = fmaxf(src_f, dst_f8->x.y);
    dst_f8->x.z = fmaxf(src_f, dst_f8->x.z);
    dst_f8->x.w = fmaxf(src_f, dst_f8->x.w);
    src_f = rpp_hip_unpack0(src_uchar12.y);
    dst_f8->x.x = fmaxf(src_f, dst_f8->x.x);
    dst_f8->x.y = fmaxf(src_f, dst_f8->x.y);
    dst_f8->x.z = fmaxf(src_f, dst_f8->x.z);
    dst_f8->x.w = fmaxf(src_f, dst_f8->x.w);
    dst_f8->y.x = fmaxf(src_f, dst_f8->y.x);
    src_f = rpp_hip_unpack1(src_uchar12.y);
    dst_f8->x.y = fmaxf(src_f, dst_f8->x.y);
    dst_f8->x.z = fmaxf(src_f, dst_f8->x.z);
    dst_f8->x.w = fmaxf(src_f, dst_f8->x.w);
    dst_f8->y.x = fmaxf(src_f, dst_f8->y.x);
    dst_f8->y.y = fmaxf(src_f, dst_f8->y.y);
    src_f = rpp_hip_unpack2(src_uchar12.y);
    dst_f8->x.z = fmaxf(src_f, dst_f8->x.z);
    dst_f8->x.w = fmaxf(src_f, dst_f8->x.w);
    dst_f8->y.x = fmaxf(src_f, dst_f8->y.x);
    dst_f8->y.y = fmaxf(src_f, dst_f8->y.y);
    dst_f8->y.z = fmaxf(src_f, dst_f8->y.z);
    src_f = rpp_hip_unpack3(src_uchar12.y);
    dst_f8->x.w = fmaxf(src_f, dst_f8->x.w);
    dst_f8->y.x = fmaxf(src_f, dst_f8->y.x);
    dst_f8->y.y = fmaxf(src_f, dst_f8->y.y);
    dst_f8->y.z = fmaxf(src_f, dst_f8->y.z);
    dst_f8->y.w = fmaxf(src_f, dst_f8->y.w);
    src_f = rpp_hip_unpack0(src_uchar12.z);
    dst_f8->y.x = fmaxf(src_f, dst_f8->y.x);
    dst_f8->y.y = fmaxf(src_f, dst_f8->y.y);
    dst_f8->y.z = fmaxf(src_f, dst_f8->y.z);
    dst_f8->y.w = fmaxf(src_f, dst_f8->y.w);
    src_f = rpp_hip_unpack1(src_uchar12.z);
    dst_f8->y.y = fmaxf(src_f, dst_f8->y.y);
    dst_f8->y.z = fmaxf(src_f, dst_f8->y.z);
    dst_f8->y.w = fmaxf(src_f, dst_f8->y.w);
    src_f = rpp_hip_unpack2(src_uchar12.z);
    dst_f8->y.z = fmaxf(src_f, dst_f8->y.z);
    dst_f8->y.w = fmaxf(src_f, dst_f8->y.w);
    src_f = rpp_hip_unpack3(src_uchar12.z);
    dst_f8->y.w = fmaxf(src_f, dst_f8->y.w);
}

__device__ void dilate_7x7_row_hip_compute(uchar *srcPtr, d_float8 *dst_f8)
{
    float src_f;
    uint4 src_uchar16 = *(uint4 *)srcPtr;
    src_f = rpp_hip_unpack0(src_uchar16.x);
    dst_f8->x.x = fmaxf(src_f, dst_f8->x.x);
    src_f = rpp_hip_unpack1(src_uchar16.x);
    dst_f8->x.x = fmaxf(src_f, dst_f8->x.x);
    dst_f8->x.y = fmaxf(src_f, dst_f8->x.y);
    src_f = rpp_hip_unpack2(src_uchar16.x);
    dst_f8->x.x = fmaxf(src_f, dst_f8->x.x);
    dst_f8->x.y = fmaxf(src_f, dst_f8->x.y);
    dst_f8->x.z = fmaxf(src_f, dst_f8->x.z);
    src_f = rpp_hip_unpack3(src_uchar16.x);
    dst_f8->x.x = fmaxf(src_f, dst_f8->x.x);
    dst_f8->x.y = fmaxf(src_f, dst_f8->x.y);
    dst_f8->x.z = fmaxf(src_f, dst_f8->x.z);
    dst_f8->x.w = fmaxf(src_f, dst_f8->x.w);
    src_f = rpp_hip_unpack0(src_uchar16.y);
    dst_f8->x.x = fmaxf(src_f, dst_f8->x.x);
    dst_f8->x.y = fmaxf(src_f, dst_f8->x.y);
    dst_f8->x.z = fmaxf(src_f, dst_f8->x.z);
    dst_f8->x.w = fmaxf(src_f, dst_f8->x.w);
    dst_f8->y.x = fmaxf(src_f, dst_f8->y.x);
    src_f = rpp_hip_unpack1(src_uchar16.y);
    dst_f8->x.x = fmaxf(src_f, dst_f8->x.x);
    dst_f8->x.y = fmaxf(src_f, dst_f8->x.y);
    dst_f8->x.z = fmaxf(src_f, dst_f8->x.z);
    dst_f8->x.w = fmaxf(src_f, dst_f8->x.w);
    dst_f8->y.x = fmaxf(src_f, dst_f8->y.x);
    dst_f8->y.y = fmaxf(src_f, dst_f8->y.y);
    src_f = rpp_hip_unpack2(src_uchar16.y);
    dst_f8->x.x = fmaxf(src_f, dst_f8->x.x);
    dst_f8->x.y = fmaxf(src_f, dst_f8->x.y);
    dst_f8->x.z = fmaxf(src_f, dst_f8->x.z);
    dst_f8->x.w = fmaxf(src_f, dst_f8->x.w);
    dst_f8->y.x = fmaxf(src_f, dst_f8->y.x);
    dst_f8->y.y = fmaxf(src_f, dst_f8->y.y);
    dst_f8->y.z = fmaxf(src_f, dst_f8->y.z);
    src_f = rpp_hip_unpack3(src_uchar16.y);
    dst_f8->x.y = fmaxf(src_f, dst_f8->x.y);
    dst_f8->x.z = fmaxf(src_f, dst_f8->x.z);
    dst_f8->x.w = fmaxf(src_f, dst_f8->x.w);
    dst_f8->y.x = fmaxf(src_f, dst_f8->y.x);
    dst_f8->y.y = fmaxf(src_f, dst_f8->y.y);
    dst_f8->y.z = fmaxf(src_f, dst_f8->y.z);
    dst_f8->y.w = fmaxf(src_f, dst_f8->y.w);
    src_f = rpp_hip_unpack0(src_uchar16.z);
    dst_f8->x.z = fmaxf(src_f, dst_f8->x.z);
    dst_f8->x.w = fmaxf(src_f, dst_f8->x.w);
    dst_f8->y.x = fmaxf(src_f, dst_f8->y.x);
    dst_f8->y.y = fmaxf(src_f, dst_f8->y.y);
    dst_f8->y.z = fmaxf(src_f, dst_f8->y.z);
    dst_f8->y.w = fmaxf(src_f, dst_f8->y.w);
    src_f = rpp_hip_unpack1(src_uchar16.z);
    dst_f8->x.w = fmaxf(src_f, dst_f8->x.w);
    dst_f8->y.x = fmaxf(src_f, dst_f8->y.x);
    dst_f8->y.y = fmaxf(src_f, dst_f8->y.y);
    dst_f8->y.z = fmaxf(src_f, dst_f8->y.z);
    dst_f8->y.w = fmaxf(src_f, dst_f8->y.w);
    src_f = rpp_hip_unpack2(src_uchar16.z);
    dst_f8->y.x = fmaxf(src_f, dst_f8->y.x);
    dst_f8->y.y = fmaxf(src_f, dst_f8->y.y);
    dst_f8->y.z = fmaxf(src_f, dst_f8->y.z);
    dst_f8->y.w = fmaxf(src_f, dst_f8->y.w);
    src_f = rpp_hip_unpack3(src_uchar16.z);
    dst_f8->y.y = fmaxf(src_f, dst_f8->y.y);
    dst_f8->y.z = fmaxf(src_f, dst_f8->y.z);
    dst_f8->y.w = fmaxf(src_f, dst_f8->y.w);
    src_f = rpp_hip_unpack0(src_uchar16.w);
    dst_f8->y.z = fmaxf(src_f, dst_f8->y.z);
    dst_f8->y.w = fmaxf(src_f, dst_f8->y.w);
    src_f = rpp_hip_unpack1(src_uchar16.w);
    dst_f8->y.w = fmaxf(src_f, dst_f8->y.w);
}

__device__ void dilate_9x9_row_hip_compute(uchar *srcPtr, d_float8 *dst_f8)
{
    float src_f;
    uint4 src_uchar16 = *(uint4 *)srcPtr;
    src_f = rpp_hip_unpack0(src_uchar16.x);
    dst_f8->x.x = fmaxf(src_f, dst_f8->x.x);
    src_f = rpp_hip_unpack1(src_uchar16.x);
    dst_f8->x.x = fmaxf(src_f, dst_f8->x.x);
    dst_f8->x.y = fmaxf(src_f, dst_f8->x.y);
    src_f = rpp_hip_unpack2(src_uchar16.x);
    dst_f8->x.x = fmaxf(src_f, dst_f8->x.x);
    dst_f8->x.y = fmaxf(src_f, dst_f8->x.y);
    dst_f8->x.z = fmaxf(src_f, dst_f8->x.z);
    src_f = rpp_hip_unpack3(src_uchar16.x);
    dst_f8->x.x = fmaxf(src_f, dst_f8->x.x);
    dst_f8->x.y = fmaxf(src_f, dst_f8->x.y);
    dst_f8->x.z = fmaxf(src_f, dst_f8->x.z);
    dst_f8->x.w = fmaxf(src_f, dst_f8->x.w);
    src_f = rpp_hip_unpack0(src_uchar16.y);
    dst_f8->x.x = fmaxf(src_f, dst_f8->x.x);
    dst_f8->x.y = fmaxf(src_f, dst_f8->x.y);
    dst_f8->x.z = fmaxf(src_f, dst_f8->x.z);
    dst_f8->x.w = fmaxf(src_f, dst_f8->x.w);
    dst_f8->y.x = fmaxf(src_f, dst_f8->y.x);
    src_f = rpp_hip_unpack1(src_uchar16.y);
    dst_f8->x.x = fmaxf(src_f, dst_f8->x.x);
    dst_f8->x.y = fmaxf(src_f, dst_f8->x.y);
    dst_f8->x.z = fmaxf(src_f, dst_f8->x.z);
    dst_f8->x.w = fmaxf(src_f, dst_f8->x.w);
    dst_f8->y.x = fmaxf(src_f, dst_f8->y.x);
    dst_f8->y.y = fmaxf(src_f, dst_f8->y.y);
    src_f = rpp_hip_unpack2(src_uchar16.y);
    dst_f8->x.x = fmaxf(src_f, dst_f8->x.x);
    dst_f8->x.y = fmaxf(src_f, dst_f8->x.y);
    dst_f8->x.z = fmaxf(src_f, dst_f8->x.z);
    dst_f8->x.w = fmaxf(src_f, dst_f8->x.w);
    dst_f8->y.x = fmaxf(src_f, dst_f8->y.x);
    dst_f8->y.y = fmaxf(src_f, dst_f8->y.y);
    dst_f8->y.z = fmaxf(src_f, dst_f8->y.z);
    src_f = rpp_hip_unpack3(src_uchar16.y);
    dst_f8->x.x = fmaxf(src_f, dst_f8->x.x);
    dst_f8->x.y = fmaxf(src_f, dst_f8->x.y);
    dst_f8->x.z = fmaxf(src_f, dst_f8->x.z);
    dst_f8->x.w = fmaxf(src_f, dst_f8->x.w);
    dst_f8->y.x = fmaxf(src_f, dst_f8->y.x);
    dst_f8->y.y = fmaxf(src_f, dst_f8->y.y);
    dst_f8->y.z = fmaxf(src_f, dst_f8->y.z);
    dst_f8->y.w = fmaxf(src_f, dst_f8->y.w);
    src_f = rpp_hip_unpack0(src_uchar16.z);
    dst_f8->x.x = fmaxf(src_f, dst_f8->x.x);
    dst_f8->x.y = fmaxf(src_f, dst_f8->x.y);
    dst_f8->x.z = fmaxf(src_f, dst_f8->x.z);
    dst_f8->x.w = fmaxf(src_f, dst_f8->x.w);
    dst_f8->y.x = fmaxf(src_f, dst_f8->y.x);
    dst_f8->y.y = fmaxf(src_f, dst_f8->y.y);
    dst_f8->y.z = fmaxf(src_f, dst_f8->y.z);
    dst_f8->y.w = fmaxf(src_f, dst_f8->y.w);
    src_f = rpp_hip_unpack1(src_uchar16.z);
    dst_f8->x.y = fmaxf(src_f, dst_f8->x.y);
    dst_f8->x.z = fmaxf(src_f, dst_f8->x.z);
    dst_f8->x.w = fmaxf(src_f, dst_f8->x.w);
    dst_f8->y.x = fmaxf(src_f, dst_f8->y.x);
    dst_f8->y.y = fmaxf(src_f, dst_f8->y.y);
    dst_f8->y.z = fmaxf(src_f, dst_f8->y.z);
    dst_f8->y.w = fmaxf(src_f, dst_f8->y.w);
    src_f = rpp_hip_unpack2(src_uchar16.z);
    dst_f8->x.z = fmaxf(src_f, dst_f8->x.z);
    dst_f8->x.w = fmaxf(src_f, dst_f8->x.w);
    dst_f8->y.x = fmaxf(src_f, dst_f8->y.x);
    dst_f8->y.y = fmaxf(src_f, dst_f8->y.y);
    dst_f8->y.z = fmaxf(src_f, dst_f8->y.z);
    dst_f8->y.w = fmaxf(src_f, dst_f8->y.w);
    src_f = rpp_hip_unpack3(src_uchar16.z);
    dst_f8->x.w = fmaxf(src_f, dst_f8->x.w);
    dst_f8->y.x = fmaxf(src_f, dst_f8->y.x);
    dst_f8->y.y = fmaxf(src_f, dst_f8->y.y);
    dst_f8->y.z = fmaxf(src_f, dst_f8->y.z);
    dst_f8->y.w = fmaxf(src_f, dst_f8->y.w);
    src_f = rpp_hip_unpack0(src_uchar16.w);
    dst_f8->y.x = fmaxf(src_f, dst_f8->y.x);
    dst_f8->y.y = fmaxf(src_f, dst_f8->y.y);
    dst_f8->y.z = fmaxf(src_f, dst_f8->y.z);
    dst_f8->y.w = fmaxf(src_f, dst_f8->y.w);
    src_f = rpp_hip_unpack1(src_uchar16.w);
    dst_f8->y.y = fmaxf(src_f, dst_f8->y.y);
    dst_f8->y.z = fmaxf(src_f, dst_f8->y.z);
    dst_f8->y.w = fmaxf(src_f, dst_f8->y.w);
    src_f = rpp_hip_unpack2(src_uchar16.w);
    dst_f8->y.z = fmaxf(src_f, dst_f8->y.z);
    dst_f8->y.w = fmaxf(src_f, dst_f8->y.w);
    src_f = rpp_hip_unpack3(src_uchar16.w);
    dst_f8->y.w = fmaxf(src_f, dst_f8->y.w);
}

// -------------------- Set 1 - PKD3->PKD3 for T = U8/F32/F16/I8 --------------------

// kernelSize = 3
template <typename T>
__global__ void dilate_3x3_pkd_tensor(T *srcPtr,
                                      uint2 srcStridesNH,
                                      T *dstPtr,
                                      uint2 dstStridesNH,
                                      uint padLength,
                                      uint2 tileSize,
                                      RpptROIPtr roiTensorPtrSrc)
{
    int hipThreadIdx_x8 = hipThreadIdx_x << 3;
    int id_x_o = (hipBlockIdx_x * tileSize.x * 8) + hipThreadIdx_x8;
    int id_y_o = hipBlockIdx_y * tileSize.y + hipThreadIdx_y;
    int id_z = hipBlockIdx_z * hipBlockDim_z + hipThreadIdx_z;

    int id_x_i = id_x_o - padLength;
    int id_y_i = id_y_o - padLength;
    d_float24 sum_f24;
    __shared__ uchar src_lds[48][128];

    int srcIdx = (id_z * srcStridesNH.x) + ((id_y_i + roiTensorPtrSrc[id_z].xywhROI.xy.y) * srcStridesNH.y) + ((id_x_i + roiTensorPtrSrc[id_z].xywhROI.xy.x) * 3);
    int dstIdx = (id_z * dstStridesNH.x) + (id_y_o * dstStridesNH.y) + id_x_o * 3;
    sum_f24.x.x = (float4) 0;
    sum_f24.x.y = (float4) 0;
    sum_f24.y.x = (float4) 0;
    sum_f24.y.y = (float4) 0;
    sum_f24.z.x = (float4) 0;
    sum_f24.z.y = (float4) 0;

    int3 hipThreadIdx_y_channel;
    hipThreadIdx_y_channel.x = hipThreadIdx_y;
    hipThreadIdx_y_channel.y = hipThreadIdx_y + 16;
    hipThreadIdx_y_channel.z = hipThreadIdx_y + 32;

    uchar *src_lds_channel[3];
    src_lds_channel[0] = &src_lds[hipThreadIdx_y_channel.x][hipThreadIdx_x8];
    src_lds_channel[1] = &src_lds[hipThreadIdx_y_channel.y][hipThreadIdx_x8];
    src_lds_channel[2] = &src_lds[hipThreadIdx_y_channel.z][hipThreadIdx_x8];

    if ((id_x_i >= -(int)padLength) && (id_x_i < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
        (id_y_i >= 0) && (id_y_i < roiTensorPtrSrc[id_z].xywhROI.roiHeight))
    {
        rpp_hip_load24_pkd3_to_uchar8_pln3(srcPtr, srcIdx, src_lds_channel);
    }
    else
    {
        *(uint2 *)src_lds_channel[0] = (uint2)0;
        *(uint2 *)src_lds_channel[1] = (uint2)0;
        *(uint2 *)src_lds_channel[2] = (uint2)0;
    }
    __syncthreads();
    if ((id_x_o < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
        (id_y_o < roiTensorPtrSrc[id_z].xywhROI.roiHeight) &&
        (hipThreadIdx_x < tileSize.x) &&
        (hipThreadIdx_y < tileSize.y))
    {
        dilate_3x3_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x][hipThreadIdx_x8], &sum_f24.x);
        dilate_3x3_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y][hipThreadIdx_x8], &sum_f24.y);
        dilate_3x3_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z][hipThreadIdx_x8], &sum_f24.z);
        dilate_3x3_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 1][hipThreadIdx_x8], &sum_f24.x);
        dilate_3x3_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 1][hipThreadIdx_x8], &sum_f24.y);
        dilate_3x3_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 1][hipThreadIdx_x8], &sum_f24.z);
        dilate_3x3_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 2][hipThreadIdx_x8], &sum_f24.x);
        dilate_3x3_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 2][hipThreadIdx_x8], &sum_f24.y);
        dilate_3x3_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 2][hipThreadIdx_x8], &sum_f24.z);
        rpp_hip_adjust_range(dstPtr, &sum_f24);
        rpp_hip_pack_float24_pln3_and_store24_pkd3(dstPtr, dstIdx, &sum_f24);
    }
}

// kernelSize = 5
template <typename T>
__global__ void dilate_5x5_pkd_tensor(T *srcPtr,
                                      uint2 srcStridesNH,
                                      T *dstPtr,
                                      uint2 dstStridesNH,
                                      uint padLength,
                                      uint2 tileSize,
                                      RpptROIPtr roiTensorPtrSrc)
{
    int hipThreadIdx_x8 = hipThreadIdx_x << 3;
    int id_x_o = (hipBlockIdx_x * tileSize.x * 8) + hipThreadIdx_x8;
    int id_y_o = hipBlockIdx_y * tileSize.y + hipThreadIdx_y;
    int id_z = hipBlockIdx_z * hipBlockDim_z + hipThreadIdx_z;

    int id_x_i = id_x_o - padLength;
    int id_y_i = id_y_o - padLength;
    d_float24 sum_f24;
    __shared__ uchar src_lds[48][128];

    int srcIdx = (id_z * srcStridesNH.x) + ((id_y_i + roiTensorPtrSrc[id_z].xywhROI.xy.y) * srcStridesNH.y) + ((id_x_i + roiTensorPtrSrc[id_z].xywhROI.xy.x) * 3);
    int dstIdx = (id_z * dstStridesNH.x) + (id_y_o * dstStridesNH.y) + id_x_o * 3;
    sum_f24.x.x = (float4) 0;
    sum_f24.x.y = (float4) 0;
    sum_f24.y.x = (float4) 0;
    sum_f24.y.y = (float4) 0;
    sum_f24.z.x = (float4) 0;
    sum_f24.z.y = (float4) 0;

    int3 hipThreadIdx_y_channel;
    hipThreadIdx_y_channel.x = hipThreadIdx_y;
    hipThreadIdx_y_channel.y = hipThreadIdx_y + 16;
    hipThreadIdx_y_channel.z = hipThreadIdx_y + 32;

    uchar *src_lds_channel[3];
    src_lds_channel[0] = &src_lds[hipThreadIdx_y_channel.x][hipThreadIdx_x8];
    src_lds_channel[1] = &src_lds[hipThreadIdx_y_channel.y][hipThreadIdx_x8];
    src_lds_channel[2] = &src_lds[hipThreadIdx_y_channel.z][hipThreadIdx_x8];

    if ((id_x_i >= -(int)padLength) && (id_x_i < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
        (id_y_i >= 0) && (id_y_i < roiTensorPtrSrc[id_z].xywhROI.roiHeight))
    {
        rpp_hip_load24_pkd3_to_uchar8_pln3(srcPtr, srcIdx, src_lds_channel);
    }
    else
    {
        *(uint2 *)src_lds_channel[0] = (uint2)0;
        *(uint2 *)src_lds_channel[1] = (uint2)0;
        *(uint2 *)src_lds_channel[2] = (uint2)0;
    }
    __syncthreads();
    if ((id_x_o < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
        (id_y_o < roiTensorPtrSrc[id_z].xywhROI.roiHeight) &&
        (hipThreadIdx_x < tileSize.x) &&
        (hipThreadIdx_y < tileSize.y))
    {
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x][hipThreadIdx_x8], &sum_f24.x);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y][hipThreadIdx_x8], &sum_f24.y);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z][hipThreadIdx_x8], &sum_f24.z);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 1][hipThreadIdx_x8], &sum_f24.x);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 1][hipThreadIdx_x8], &sum_f24.y);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 1][hipThreadIdx_x8], &sum_f24.z);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 2][hipThreadIdx_x8], &sum_f24.x);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 2][hipThreadIdx_x8], &sum_f24.y);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 2][hipThreadIdx_x8], &sum_f24.z);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 3][hipThreadIdx_x8], &sum_f24.x);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 3][hipThreadIdx_x8], &sum_f24.y);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 3][hipThreadIdx_x8], &sum_f24.z);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 4][hipThreadIdx_x8], &sum_f24.x);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 4][hipThreadIdx_x8], &sum_f24.y);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 4][hipThreadIdx_x8], &sum_f24.z);
        rpp_hip_adjust_range(dstPtr, &sum_f24);
        rpp_hip_pack_float24_pln3_and_store24_pkd3(dstPtr, dstIdx, &sum_f24);
    }
}

// kernelSize = 7
template <typename T>
__global__ void dilate_7x7_pkd_tensor(T *srcPtr,
                                      uint2 srcStridesNH,
                                      T *dstPtr,
                                      uint2 dstStridesNH,
                                      uint padLength,
                                      uint2 tileSize,
                                      RpptROIPtr roiTensorPtrSrc)
{
    int hipThreadIdx_x8 = hipThreadIdx_x << 3;
    int id_x_o = (hipBlockIdx_x * tileSize.x * 8) + hipThreadIdx_x8;
    int id_y_o = hipBlockIdx_y * tileSize.y + hipThreadIdx_y;
    int id_z = hipBlockIdx_z * hipBlockDim_z + hipThreadIdx_z;

    int id_x_i = id_x_o - padLength;
    int id_y_i = id_y_o - padLength;
    d_float24 sum_f24;
    __shared__ uchar src_lds[48][128];

    int srcIdx = (id_z * srcStridesNH.x) + ((id_y_i + roiTensorPtrSrc[id_z].xywhROI.xy.y) * srcStridesNH.y) + ((id_x_i + roiTensorPtrSrc[id_z].xywhROI.xy.x) * 3);
    int dstIdx = (id_z * dstStridesNH.x) + (id_y_o * dstStridesNH.y) + id_x_o * 3;
    sum_f24.x.x = (float4) 0;
    sum_f24.x.y = (float4) 0;
    sum_f24.y.x = (float4) 0;
    sum_f24.y.y = (float4) 0;
    sum_f24.z.x = (float4) 0;
    sum_f24.z.y = (float4) 0;

    int3 hipThreadIdx_y_channel;
    hipThreadIdx_y_channel.x = hipThreadIdx_y;
    hipThreadIdx_y_channel.y = hipThreadIdx_y + 16;
    hipThreadIdx_y_channel.z = hipThreadIdx_y + 32;

    uchar *src_lds_channel[3];
    src_lds_channel[0] = &src_lds[hipThreadIdx_y_channel.x][hipThreadIdx_x8];
    src_lds_channel[1] = &src_lds[hipThreadIdx_y_channel.y][hipThreadIdx_x8];
    src_lds_channel[2] = &src_lds[hipThreadIdx_y_channel.z][hipThreadIdx_x8];

    if ((id_x_i >= -(int)padLength) && (id_x_i < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
        (id_y_i >= 0) && (id_y_i < roiTensorPtrSrc[id_z].xywhROI.roiHeight))
    {
        rpp_hip_load24_pkd3_to_uchar8_pln3(srcPtr, srcIdx, src_lds_channel);
    }
    else
    {
        *(uint2 *)src_lds_channel[0] = (uint2)0;
        *(uint2 *)src_lds_channel[1] = (uint2)0;
        *(uint2 *)src_lds_channel[2] = (uint2)0;
    }
    __syncthreads();
    if ((id_x_o < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
        (id_y_o < roiTensorPtrSrc[id_z].xywhROI.roiHeight) &&
        (hipThreadIdx_x < tileSize.x) &&
        (hipThreadIdx_y < tileSize.y))
    {
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x][hipThreadIdx_x8], &sum_f24.x);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y][hipThreadIdx_x8], &sum_f24.y);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z][hipThreadIdx_x8], &sum_f24.z);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 1][hipThreadIdx_x8], &sum_f24.x);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 1][hipThreadIdx_x8], &sum_f24.y);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 1][hipThreadIdx_x8], &sum_f24.z);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 2][hipThreadIdx_x8], &sum_f24.x);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 2][hipThreadIdx_x8], &sum_f24.y);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 2][hipThreadIdx_x8], &sum_f24.z);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 3][hipThreadIdx_x8], &sum_f24.x);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 3][hipThreadIdx_x8], &sum_f24.y);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 3][hipThreadIdx_x8], &sum_f24.z);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 4][hipThreadIdx_x8], &sum_f24.x);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 4][hipThreadIdx_x8], &sum_f24.y);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 4][hipThreadIdx_x8], &sum_f24.z);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 5][hipThreadIdx_x8], &sum_f24.x);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 5][hipThreadIdx_x8], &sum_f24.y);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 5][hipThreadIdx_x8], &sum_f24.z);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 6][hipThreadIdx_x8], &sum_f24.x);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 6][hipThreadIdx_x8], &sum_f24.y);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 6][hipThreadIdx_x8], &sum_f24.z);
        rpp_hip_adjust_range(dstPtr, &sum_f24);
        rpp_hip_pack_float24_pln3_and_store24_pkd3(dstPtr, dstIdx, &sum_f24);
    }
}

// kernelSize = 9
template <typename T>
__global__ void dilate_9x9_pkd_tensor(T *srcPtr,
                                      uint2 srcStridesNH,
                                      T *dstPtr,
                                      uint2 dstStridesNH,
                                      uint padLength,
                                      uint2 tileSize,
                                      RpptROIPtr roiTensorPtrSrc)
{
    int hipThreadIdx_x8 = hipThreadIdx_x << 3;
    int id_x_o = (hipBlockIdx_x * tileSize.x * 8) + hipThreadIdx_x8;
    int id_y_o = hipBlockIdx_y * tileSize.y + hipThreadIdx_y;
    int id_z = hipBlockIdx_z * hipBlockDim_z + hipThreadIdx_z;

    int id_x_i = id_x_o - padLength;
    int id_y_i = id_y_o - padLength;
    d_float24 sum_f24;
    __shared__ uchar src_lds[48][128];

    int srcIdx = (id_z * srcStridesNH.x) + ((id_y_i + roiTensorPtrSrc[id_z].xywhROI.xy.y) * srcStridesNH.y) + ((id_x_i + roiTensorPtrSrc[id_z].xywhROI.xy.x) * 3);
    int dstIdx = (id_z * dstStridesNH.x) + (id_y_o * dstStridesNH.y) + id_x_o * 3;
    sum_f24.x.x = (float4) 0;
    sum_f24.x.y = (float4) 0;
    sum_f24.y.x = (float4) 0;
    sum_f24.y.y = (float4) 0;
    sum_f24.z.x = (float4) 0;
    sum_f24.z.y = (float4) 0;

    int3 hipThreadIdx_y_channel;
    hipThreadIdx_y_channel.x = hipThreadIdx_y;
    hipThreadIdx_y_channel.y = hipThreadIdx_y + 16;
    hipThreadIdx_y_channel.z = hipThreadIdx_y + 32;

    uchar *src_lds_channel[3];
    src_lds_channel[0] = &src_lds[hipThreadIdx_y_channel.x][hipThreadIdx_x8];
    src_lds_channel[1] = &src_lds[hipThreadIdx_y_channel.y][hipThreadIdx_x8];
    src_lds_channel[2] = &src_lds[hipThreadIdx_y_channel.z][hipThreadIdx_x8];

    if ((id_x_i >= -(int)padLength) && (id_x_i < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
        (id_y_i >= 0) && (id_y_i < roiTensorPtrSrc[id_z].xywhROI.roiHeight))
    {
        rpp_hip_load24_pkd3_to_uchar8_pln3(srcPtr, srcIdx, src_lds_channel);
    }
    else
    {
        *(uint2 *)src_lds_channel[0] = (uint2)0;
        *(uint2 *)src_lds_channel[1] = (uint2)0;
        *(uint2 *)src_lds_channel[2] = (uint2)0;
    }
    __syncthreads();
    if ((id_x_o < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
        (id_y_o < roiTensorPtrSrc[id_z].xywhROI.roiHeight) &&
        (hipThreadIdx_x < tileSize.x) &&
        (hipThreadIdx_y < tileSize.y))
    {
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x][hipThreadIdx_x8], &sum_f24.x);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y][hipThreadIdx_x8], &sum_f24.y);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z][hipThreadIdx_x8], &sum_f24.z);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 1][hipThreadIdx_x8], &sum_f24.x);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 1][hipThreadIdx_x8], &sum_f24.y);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 1][hipThreadIdx_x8], &sum_f24.z);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 2][hipThreadIdx_x8], &sum_f24.x);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 2][hipThreadIdx_x8], &sum_f24.y);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 2][hipThreadIdx_x8], &sum_f24.z);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 3][hipThreadIdx_x8], &sum_f24.x);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 3][hipThreadIdx_x8], &sum_f24.y);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 3][hipThreadIdx_x8], &sum_f24.z);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 4][hipThreadIdx_x8], &sum_f24.x);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 4][hipThreadIdx_x8], &sum_f24.y);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 4][hipThreadIdx_x8], &sum_f24.z);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 5][hipThreadIdx_x8], &sum_f24.x);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 5][hipThreadIdx_x8], &sum_f24.y);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 5][hipThreadIdx_x8], &sum_f24.z);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 6][hipThreadIdx_x8], &sum_f24.x);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 6][hipThreadIdx_x8], &sum_f24.y);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 6][hipThreadIdx_x8], &sum_f24.z);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 7][hipThreadIdx_x8], &sum_f24.x);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 7][hipThreadIdx_x8], &sum_f24.y);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 7][hipThreadIdx_x8], &sum_f24.z);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 8][hipThreadIdx_x8], &sum_f24.x);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 8][hipThreadIdx_x8], &sum_f24.y);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 8][hipThreadIdx_x8], &sum_f24.z);
        rpp_hip_adjust_range(dstPtr, &sum_f24);
        rpp_hip_pack_float24_pln3_and_store24_pkd3(dstPtr, dstIdx, &sum_f24);
    }
}

// -------------------- Set 2 - PLN1->PLN1, PLN3->PLN3 for T = U8/F32/F16/I8 --------------------

// kernelSize = 3
template <typename T>
__global__ void dilate_3x3_pln_tensor(T *srcPtr,
                                      uint3 srcStridesNCH,
                                      T *dstPtr,
                                      uint3 dstStridesNCH,
                                      int channelsDst,
                                      uint padLength,
                                      uint2 tileSize,
                                      RpptROIPtr roiTensorPtrSrc)
{
    int hipThreadIdx_x8 = hipThreadIdx_x << 3;
    int id_x_o = (hipBlockIdx_x * tileSize.x * 8) + hipThreadIdx_x8;
    int id_y_o = hipBlockIdx_y * tileSize.y + hipThreadIdx_y;
    int id_z = hipBlockIdx_z * hipBlockDim_z + hipThreadIdx_z;

    int id_x_i = id_x_o - padLength;
    int id_y_i = id_y_o - padLength;
    d_float8 sum_f8;
    __shared__ uchar src_lds[16][128];

    int srcIdx = (id_z * srcStridesNCH.x) + ((id_y_i + roiTensorPtrSrc[id_z].xywhROI.xy.y) * srcStridesNCH.z) + (id_x_i + roiTensorPtrSrc[id_z].xywhROI.xy.x);
    int dstIdx = (id_z * dstStridesNCH.x) + (id_y_o * dstStridesNCH.z) + id_x_o;
    sum_f8.x = (float4) 0;
    sum_f8.y = (float4) 0;
    if ((id_x_i >= -(int)padLength) && (id_x_i < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
        (id_y_i >= 0) && (id_y_i < roiTensorPtrSrc[id_z].xywhROI.roiHeight))
        rpp_hip_load8_to_uchar8(srcPtr, srcIdx, &src_lds[hipThreadIdx_y][hipThreadIdx_x8]);
    else
        *(uint2 *)&src_lds[hipThreadIdx_y][hipThreadIdx_x8] = (uint2)0;
    __syncthreads();
    if ((id_x_o < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
        (id_y_o < roiTensorPtrSrc[id_z].xywhROI.roiHeight) &&
        (hipThreadIdx_x < tileSize.x) &&
        (hipThreadIdx_y < tileSize.y))
    {
        dilate_3x3_row_hip_compute(&src_lds[hipThreadIdx_y][hipThreadIdx_x8], &sum_f8);
        dilate_3x3_row_hip_compute(&src_lds[hipThreadIdx_y + 1][hipThreadIdx_x8], &sum_f8);
        dilate_3x3_row_hip_compute(&src_lds[hipThreadIdx_y + 2][hipThreadIdx_x8], &sum_f8);
        rpp_hip_adjust_range(dstPtr, &sum_f8);
        rpp_hip_pack_float8_and_store8(dstPtr, dstIdx, &sum_f8);
    }

    if (channelsDst == 3)
    {
        __syncthreads();
        srcIdx += srcStridesNCH.y;
        dstIdx += dstStridesNCH.y;
        sum_f8.x = (float4) 0;
        sum_f8.y = (float4) 0;
        if ((id_x_i >= -(int)padLength) && (id_x_i < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
            (id_y_i >= 0) && (id_y_i < roiTensorPtrSrc[id_z].xywhROI.roiHeight))
            rpp_hip_load8_to_uchar8(srcPtr, srcIdx, &src_lds[hipThreadIdx_y][hipThreadIdx_x8]);
        else
            *(uint2 *)&src_lds[hipThreadIdx_y][hipThreadIdx_x8] = (uint2)0;
        __syncthreads();
        if ((id_x_o < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
            (id_y_o < roiTensorPtrSrc[id_z].xywhROI.roiHeight) &&
            (hipThreadIdx_x < tileSize.x) &&
            (hipThreadIdx_y < tileSize.y))
        {
            dilate_3x3_row_hip_compute(&src_lds[hipThreadIdx_y][hipThreadIdx_x8], &sum_f8);
            dilate_3x3_row_hip_compute(&src_lds[hipThreadIdx_y + 1][hipThreadIdx_x8], &sum_f8);
            dilate_3x3_row_hip_compute(&src_lds[hipThreadIdx_y + 2][hipThreadIdx_x8], &sum_f8);
            rpp_hip_adjust_range(dstPtr, &sum_f8);
            rpp_hip_pack_float8_and_store8(dstPtr, dstIdx, &sum_f8);
        }

        __syncthreads();
        srcIdx += srcStridesNCH.y;
        dstIdx += dstStridesNCH.y;
        sum_f8.x = (float4) 0;
        sum_f8.y = (float4) 0;
        if ((id_x_i >= -(int)padLength) && (id_x_i < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
            (id_y_i >= 0) && (id_y_i < roiTensorPtrSrc[id_z].xywhROI.roiHeight))
            rpp_hip_load8_to_uchar8(srcPtr, srcIdx, &src_lds[hipThreadIdx_y][hipThreadIdx_x8]);
        else
            *(uint2 *)&src_lds[hipThreadIdx_y][hipThreadIdx_x8] = (uint2)0;
        __syncthreads();
        if ((id_x_o < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
            (id_y_o < roiTensorPtrSrc[id_z].xywhROI.roiHeight) &&
            (hipThreadIdx_x < tileSize.x) &&
            (hipThreadIdx_y < tileSize.y))
        {
            dilate_3x3_row_hip_compute(&src_lds[hipThreadIdx_y][hipThreadIdx_x8], &sum_f8);
            dilate_3x3_row_hip_compute(&src_lds[hipThreadIdx_y + 1][hipThreadIdx_x8], &sum_f8);
            dilate_3x3_row_hip_compute(&src_lds[hipThreadIdx_y + 2][hipThreadIdx_x8], &sum_f8);
            rpp_hip_adjust_range(dstPtr, &sum_f8);
            rpp_hip_pack_float8_and_store8(dstPtr, dstIdx, &sum_f8);
        }
    }
}

// kernelSize = 5
template <typename T>
__global__ void dilate_5x5_pln_tensor(T *srcPtr,
                                      uint3 srcStridesNCH,
                                      T *dstPtr,
                                      uint3 dstStridesNCH,
                                      int channelsDst,
                                      uint padLength,
                                      uint2 tileSize,
                                      RpptROIPtr roiTensorPtrSrc)
{
    int hipThreadIdx_x8 = hipThreadIdx_x << 3;
    int id_x_o = (hipBlockIdx_x * tileSize.x * 8) + hipThreadIdx_x8;
    int id_y_o = hipBlockIdx_y * tileSize.y + hipThreadIdx_y;
    int id_z = hipBlockIdx_z * hipBlockDim_z + hipThreadIdx_z;

    int id_x_i = id_x_o - padLength;
    int id_y_i = id_y_o - padLength;
    d_float8 sum_f8;
    __shared__ uchar src_lds[16][128];

    int srcIdx = (id_z * srcStridesNCH.x) + ((id_y_i + roiTensorPtrSrc[id_z].xywhROI.xy.y) * srcStridesNCH.z) + (id_x_i + roiTensorPtrSrc[id_z].xywhROI.xy.x);
    int dstIdx = (id_z * dstStridesNCH.x) + (id_y_o * dstStridesNCH.z) + id_x_o;
    sum_f8.x = (float4) 0;
    sum_f8.y = (float4) 0;
    if ((id_x_i >= -(int)padLength) && (id_x_i < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
        (id_y_i >= 0) && (id_y_i < roiTensorPtrSrc[id_z].xywhROI.roiHeight))
        rpp_hip_load8_to_uchar8(srcPtr, srcIdx, &src_lds[hipThreadIdx_y][hipThreadIdx_x8]);
    else
        *(uint2 *)&src_lds[hipThreadIdx_y][hipThreadIdx_x8] = (uint2)0;
    __syncthreads();
    if ((id_x_o < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
        (id_y_o < roiTensorPtrSrc[id_z].xywhROI.roiHeight) &&
        (hipThreadIdx_x < tileSize.x) &&
        (hipThreadIdx_y < tileSize.y))
    {
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y][hipThreadIdx_x8], &sum_f8);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y + 1][hipThreadIdx_x8], &sum_f8);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y + 2][hipThreadIdx_x8], &sum_f8);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y + 3][hipThreadIdx_x8], &sum_f8);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y + 4][hipThreadIdx_x8], &sum_f8);
        rpp_hip_adjust_range(dstPtr, &sum_f8);
        rpp_hip_pack_float8_and_store8(dstPtr, dstIdx, &sum_f8);
    }

    if (channelsDst == 3)
    {
        __syncthreads();
        srcIdx += srcStridesNCH.y;
        dstIdx += dstStridesNCH.y;
        sum_f8.x = (float4) 0;
        sum_f8.y = (float4) 0;
        if ((id_x_i >= -(int)padLength) && (id_x_i < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
            (id_y_i >= 0) && (id_y_i < roiTensorPtrSrc[id_z].xywhROI.roiHeight))
            rpp_hip_load8_to_uchar8(srcPtr, srcIdx, &src_lds[hipThreadIdx_y][hipThreadIdx_x8]);
        else
            *(uint2 *)&src_lds[hipThreadIdx_y][hipThreadIdx_x8] = (uint2)0;
        __syncthreads();
        if ((id_x_o < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
            (id_y_o < roiTensorPtrSrc[id_z].xywhROI.roiHeight) &&
            (hipThreadIdx_x < tileSize.x) &&
            (hipThreadIdx_y < tileSize.y))
        {
            dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y][hipThreadIdx_x8], &sum_f8);
            dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y + 1][hipThreadIdx_x8], &sum_f8);
            dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y + 2][hipThreadIdx_x8], &sum_f8);
            dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y + 3][hipThreadIdx_x8], &sum_f8);
            dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y + 4][hipThreadIdx_x8], &sum_f8);
            rpp_hip_adjust_range(dstPtr, &sum_f8);
            rpp_hip_pack_float8_and_store8(dstPtr, dstIdx, &sum_f8);
        }

        __syncthreads();
        srcIdx += srcStridesNCH.y;
        dstIdx += dstStridesNCH.y;
        sum_f8.x = (float4) 0;
        sum_f8.y = (float4) 0;
        if ((id_x_i >= -(int)padLength) && (id_x_i < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
            (id_y_i >= 0) && (id_y_i < roiTensorPtrSrc[id_z].xywhROI.roiHeight))
            rpp_hip_load8_to_uchar8(srcPtr, srcIdx, &src_lds[hipThreadIdx_y][hipThreadIdx_x8]);
        else
            *(uint2 *)&src_lds[hipThreadIdx_y][hipThreadIdx_x8] = (uint2)0;
        __syncthreads();
        if ((id_x_o < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
            (id_y_o < roiTensorPtrSrc[id_z].xywhROI.roiHeight) &&
            (hipThreadIdx_x < tileSize.x) &&
            (hipThreadIdx_y < tileSize.y))
        {
            dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y][hipThreadIdx_x8], &sum_f8);
            dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y + 1][hipThreadIdx_x8], &sum_f8);
            dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y + 2][hipThreadIdx_x8], &sum_f8);
            dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y + 3][hipThreadIdx_x8], &sum_f8);
            dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y + 4][hipThreadIdx_x8], &sum_f8);
            rpp_hip_adjust_range(dstPtr, &sum_f8);
            rpp_hip_pack_float8_and_store8(dstPtr, dstIdx, &sum_f8);
        }
    }
}

// kernelSize = 7
template <typename T>
__global__ void dilate_7x7_pln_tensor(T *srcPtr,
                                      uint3 srcStridesNCH,
                                      T *dstPtr,
                                      uint3 dstStridesNCH,
                                      int channelsDst,
                                      uint padLength,
                                      uint2 tileSize,
                                      RpptROIPtr roiTensorPtrSrc)
{
    int hipThreadIdx_x8 = hipThreadIdx_x << 3;
    int id_x_o = (hipBlockIdx_x * tileSize.x * 8) + hipThreadIdx_x8;
    int id_y_o = hipBlockIdx_y * tileSize.y + hipThreadIdx_y;
    int id_z = hipBlockIdx_z * hipBlockDim_z + hipThreadIdx_z;

    int id_x_i = id_x_o - padLength;
    int id_y_i = id_y_o - padLength;
    d_float8 sum_f8;
    __shared__ uchar src_lds[16][128];

    int srcIdx = (id_z * srcStridesNCH.x) + ((id_y_i + roiTensorPtrSrc[id_z].xywhROI.xy.y) * srcStridesNCH.z) + (id_x_i + roiTensorPtrSrc[id_z].xywhROI.xy.x);
    int dstIdx = (id_z * dstStridesNCH.x) + (id_y_o * dstStridesNCH.z) + id_x_o;
    sum_f8.x = (float4) 0;
    sum_f8.y = (float4) 0;
    if ((id_x_i >= -(int)padLength) && (id_x_i < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
        (id_y_i >= 0) && (id_y_i < roiTensorPtrSrc[id_z].xywhROI.roiHeight))
        rpp_hip_load8_to_uchar8(srcPtr, srcIdx, &src_lds[hipThreadIdx_y][hipThreadIdx_x8]);
    else
        *(uint2 *)&src_lds[hipThreadIdx_y][hipThreadIdx_x8] = (uint2)0;
    __syncthreads();
    if ((id_x_o < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
        (id_y_o < roiTensorPtrSrc[id_z].xywhROI.roiHeight) &&
        (hipThreadIdx_x < tileSize.x) &&
        (hipThreadIdx_y < tileSize.y))
    {
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y][hipThreadIdx_x8], &sum_f8);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y + 1][hipThreadIdx_x8], &sum_f8);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y + 2][hipThreadIdx_x8], &sum_f8);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y + 3][hipThreadIdx_x8], &sum_f8);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y + 4][hipThreadIdx_x8], &sum_f8);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y + 5][hipThreadIdx_x8], &sum_f8);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y + 6][hipThreadIdx_x8], &sum_f8);
        rpp_hip_adjust_range(dstPtr, &sum_f8);
        rpp_hip_pack_float8_and_store8(dstPtr, dstIdx, &sum_f8);
    }

    if (channelsDst == 3)
    {
        __syncthreads();
        srcIdx += srcStridesNCH.y;
        dstIdx += dstStridesNCH.y;
        sum_f8.x = (float4) 0;
        sum_f8.y = (float4) 0;
        if ((id_x_i >= -(int)padLength) && (id_x_i < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
            (id_y_i >= 0) && (id_y_i < roiTensorPtrSrc[id_z].xywhROI.roiHeight))
            rpp_hip_load8_to_uchar8(srcPtr, srcIdx, &src_lds[hipThreadIdx_y][hipThreadIdx_x8]);
        else
            *(uint2 *)&src_lds[hipThreadIdx_y][hipThreadIdx_x8] = (uint2)0;
        __syncthreads();
        if ((id_x_o < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
            (id_y_o < roiTensorPtrSrc[id_z].xywhROI.roiHeight) &&
            (hipThreadIdx_x < tileSize.x) &&
            (hipThreadIdx_y < tileSize.y))
        {
            dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y][hipThreadIdx_x8], &sum_f8);
            dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y + 1][hipThreadIdx_x8], &sum_f8);
            dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y + 2][hipThreadIdx_x8], &sum_f8);
            dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y + 3][hipThreadIdx_x8], &sum_f8);
            dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y + 4][hipThreadIdx_x8], &sum_f8);
            dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y + 5][hipThreadIdx_x8], &sum_f8);
            dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y + 6][hipThreadIdx_x8], &sum_f8);
            rpp_hip_adjust_range(dstPtr, &sum_f8);
            rpp_hip_pack_float8_and_store8(dstPtr, dstIdx, &sum_f8);
        }

        __syncthreads();
        srcIdx += srcStridesNCH.y;
        dstIdx += dstStridesNCH.y;
        sum_f8.x = (float4) 0;
        sum_f8.y = (float4) 0;
        if ((id_x_i >= -(int)padLength) && (id_x_i < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
            (id_y_i >= 0) && (id_y_i < roiTensorPtrSrc[id_z].xywhROI.roiHeight))
            rpp_hip_load8_to_uchar8(srcPtr, srcIdx, &src_lds[hipThreadIdx_y][hipThreadIdx_x8]);
        else
            *(uint2 *)&src_lds[hipThreadIdx_y][hipThreadIdx_x8] = (uint2)0;
        __syncthreads();
        if ((id_x_o < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
            (id_y_o < roiTensorPtrSrc[id_z].xywhROI.roiHeight) &&
            (hipThreadIdx_x < tileSize.x) &&
            (hipThreadIdx_y < tileSize.y))
        {
            dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y][hipThreadIdx_x8], &sum_f8);
            dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y + 1][hipThreadIdx_x8], &sum_f8);
            dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y + 2][hipThreadIdx_x8], &sum_f8);
            dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y + 3][hipThreadIdx_x8], &sum_f8);
            dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y + 4][hipThreadIdx_x8], &sum_f8);
            dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y + 5][hipThreadIdx_x8], &sum_f8);
            dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y + 6][hipThreadIdx_x8], &sum_f8);
            rpp_hip_adjust_range(dstPtr, &sum_f8);
            rpp_hip_pack_float8_and_store8(dstPtr, dstIdx, &sum_f8);
        }
    }
}

// kernelSize = 9
template <typename T>
__global__ void dilate_9x9_pln_tensor(T *srcPtr,
                                      uint3 srcStridesNCH,
                                      T *dstPtr,
                                      uint3 dstStridesNCH,
                                      int channelsDst,
                                      uint padLength,
                                      uint2 tileSize,
                                      RpptROIPtr roiTensorPtrSrc)
{
    int hipThreadIdx_x8 = hipThreadIdx_x << 3;
    int id_x_o = (hipBlockIdx_x * tileSize.x * 8) + hipThreadIdx_x8;
    int id_y_o = hipBlockIdx_y * tileSize.y + hipThreadIdx_y;
    int id_z = hipBlockIdx_z * hipBlockDim_z + hipThreadIdx_z;

    int id_x_i = id_x_o - padLength;
    int id_y_i = id_y_o - padLength;
    d_float8 sum_f8;
    __shared__ uchar src_lds[16][128];

    int srcIdx = (id_z * srcStridesNCH.x) + ((id_y_i + roiTensorPtrSrc[id_z].xywhROI.xy.y) * srcStridesNCH.z) + (id_x_i + roiTensorPtrSrc[id_z].xywhROI.xy.x);
    int dstIdx = (id_z * dstStridesNCH.x) + (id_y_o * dstStridesNCH.z) + id_x_o;
    sum_f8.x = (float4) 0;
    sum_f8.y = (float4) 0;
    if ((id_x_i >= -(int)padLength) && (id_x_i < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
        (id_y_i >= 0) && (id_y_i < roiTensorPtrSrc[id_z].xywhROI.roiHeight))
        rpp_hip_load8_to_uchar8(srcPtr, srcIdx, &src_lds[hipThreadIdx_y][hipThreadIdx_x8]);
    else
        *(uint2 *)&src_lds[hipThreadIdx_y][hipThreadIdx_x8] = (uint2)0;
    __syncthreads();
    if ((id_x_o < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
        (id_y_o < roiTensorPtrSrc[id_z].xywhROI.roiHeight) &&
        (hipThreadIdx_x < tileSize.x) &&
        (hipThreadIdx_y < tileSize.y))
    {
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y][hipThreadIdx_x8], &sum_f8);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y + 1][hipThreadIdx_x8], &sum_f8);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y + 2][hipThreadIdx_x8], &sum_f8);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y + 3][hipThreadIdx_x8], &sum_f8);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y + 4][hipThreadIdx_x8], &sum_f8);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y + 5][hipThreadIdx_x8], &sum_f8);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y + 6][hipThreadIdx_x8], &sum_f8);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y + 7][hipThreadIdx_x8], &sum_f8);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y + 8][hipThreadIdx_x8], &sum_f8);
        rpp_hip_adjust_range(dstPtr, &sum_f8);
        rpp_hip_pack_float8_and_store8(dstPtr, dstIdx, &sum_f8);
    }

    if (channelsDst == 3)
    {
        __syncthreads();
        srcIdx += srcStridesNCH.y;
        dstIdx += dstStridesNCH.y;
        sum_f8.x = (float4) 0;
        sum_f8.y = (float4) 0;
        if ((id_x_i >= -(int)padLength) && (id_x_i < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
            (id_y_i >= 0) && (id_y_i < roiTensorPtrSrc[id_z].xywhROI.roiHeight))
            rpp_hip_load8_to_uchar8(srcPtr, srcIdx, &src_lds[hipThreadIdx_y][hipThreadIdx_x8]);
        else
            *(uint2 *)&src_lds[hipThreadIdx_y][hipThreadIdx_x8] = (uint2)0;
        __syncthreads();
        if ((id_x_o < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
            (id_y_o < roiTensorPtrSrc[id_z].xywhROI.roiHeight) &&
            (hipThreadIdx_x < tileSize.x) &&
            (hipThreadIdx_y < tileSize.y))
        {
            dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y][hipThreadIdx_x8], &sum_f8);
            dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y + 1][hipThreadIdx_x8], &sum_f8);
            dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y + 2][hipThreadIdx_x8], &sum_f8);
            dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y + 3][hipThreadIdx_x8], &sum_f8);
            dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y + 4][hipThreadIdx_x8], &sum_f8);
            dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y + 5][hipThreadIdx_x8], &sum_f8);
            dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y + 6][hipThreadIdx_x8], &sum_f8);
            dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y + 7][hipThreadIdx_x8], &sum_f8);
            dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y + 8][hipThreadIdx_x8], &sum_f8);
            rpp_hip_adjust_range(dstPtr, &sum_f8);
            rpp_hip_pack_float8_and_store8(dstPtr, dstIdx, &sum_f8);
        }

        __syncthreads();
        srcIdx += srcStridesNCH.y;
        dstIdx += dstStridesNCH.y;
        sum_f8.x = (float4) 0;
        sum_f8.y = (float4) 0;
        if ((id_x_i >= -(int)padLength) && (id_x_i < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
            (id_y_i >= 0) && (id_y_i < roiTensorPtrSrc[id_z].xywhROI.roiHeight))
            rpp_hip_load8_to_uchar8(srcPtr, srcIdx, &src_lds[hipThreadIdx_y][hipThreadIdx_x8]);
        else
            *(uint2 *)&src_lds[hipThreadIdx_y][hipThreadIdx_x8] = (uint2)0;
        __syncthreads();
        if ((id_x_o < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
            (id_y_o < roiTensorPtrSrc[id_z].xywhROI.roiHeight) &&
            (hipThreadIdx_x < tileSize.x) &&
            (hipThreadIdx_y < tileSize.y))
        {
            dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y][hipThreadIdx_x8], &sum_f8);
            dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y + 1][hipThreadIdx_x8], &sum_f8);
            dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y + 2][hipThreadIdx_x8], &sum_f8);
            dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y + 3][hipThreadIdx_x8], &sum_f8);
            dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y + 4][hipThreadIdx_x8], &sum_f8);
            dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y + 5][hipThreadIdx_x8], &sum_f8);
            dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y + 6][hipThreadIdx_x8], &sum_f8);
            dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y + 7][hipThreadIdx_x8], &sum_f8);
            dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y + 8][hipThreadIdx_x8], &sum_f8);
            rpp_hip_adjust_range(dstPtr, &sum_f8);
            rpp_hip_pack_float8_and_store8(dstPtr, dstIdx, &sum_f8);
        }
    }
}

// -------------------- Set 3 - PKD3->PLN3 for T = U8/F32/F16/I8 --------------------

// kernelSize = 3
template <typename T>
__global__ void dilate_3x3_pkd3_pln3_tensor(T *srcPtr,
                                            uint2 srcStridesNH,
                                            T *dstPtr,
                                            uint3 dstStridesNCH,
                                            uint padLength,
                                            uint2 tileSize,
                                            RpptROIPtr roiTensorPtrSrc)
{
    int hipThreadIdx_x8 = hipThreadIdx_x << 3;
    int id_x_o = (hipBlockIdx_x * tileSize.x * 8) + hipThreadIdx_x8;
    int id_y_o = hipBlockIdx_y * tileSize.y + hipThreadIdx_y;
    int id_z = hipBlockIdx_z * hipBlockDim_z + hipThreadIdx_z;

    int id_x_i = id_x_o - padLength;
    int id_y_i = id_y_o - padLength;
    d_float24 sum_f24;
    __shared__ uchar src_lds[48][128];

    int srcIdx = (id_z * srcStridesNH.x) + ((id_y_i + roiTensorPtrSrc[id_z].xywhROI.xy.y) * srcStridesNH.y) + ((id_x_i + roiTensorPtrSrc[id_z].xywhROI.xy.x) * 3);
    int dstIdx = (id_z * dstStridesNCH.x) + (id_y_o * dstStridesNCH.z) + id_x_o;
    sum_f24.x.x = (float4) 0;
    sum_f24.x.y = (float4) 0;
    sum_f24.y.x = (float4) 0;
    sum_f24.y.y = (float4) 0;
    sum_f24.z.x = (float4) 0;
    sum_f24.z.y = (float4) 0;

    int3 hipThreadIdx_y_channel;
    hipThreadIdx_y_channel.x = hipThreadIdx_y;
    hipThreadIdx_y_channel.y = hipThreadIdx_y + 16;
    hipThreadIdx_y_channel.z = hipThreadIdx_y + 32;

    uchar *src_lds_channel[3];
    src_lds_channel[0] = &src_lds[hipThreadIdx_y_channel.x][hipThreadIdx_x8];
    src_lds_channel[1] = &src_lds[hipThreadIdx_y_channel.y][hipThreadIdx_x8];
    src_lds_channel[2] = &src_lds[hipThreadIdx_y_channel.z][hipThreadIdx_x8];

    if ((id_x_i >= -(int)padLength) && (id_x_i < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
        (id_y_i >= 0) && (id_y_i < roiTensorPtrSrc[id_z].xywhROI.roiHeight))
    {
        rpp_hip_load24_pkd3_to_uchar8_pln3(srcPtr, srcIdx, src_lds_channel);
    }
    else
    {
        *(uint2 *)src_lds_channel[0] = (uint2)0;
        *(uint2 *)src_lds_channel[1] = (uint2)0;
        *(uint2 *)src_lds_channel[2] = (uint2)0;
    }
    __syncthreads();
    if ((id_x_o < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
        (id_y_o < roiTensorPtrSrc[id_z].xywhROI.roiHeight) &&
        (hipThreadIdx_x < tileSize.x) &&
        (hipThreadIdx_y < tileSize.y))
    {
        dilate_3x3_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x][hipThreadIdx_x8], &sum_f24.x);
        dilate_3x3_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y][hipThreadIdx_x8], &sum_f24.y);
        dilate_3x3_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z][hipThreadIdx_x8], &sum_f24.z);
        dilate_3x3_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 1][hipThreadIdx_x8], &sum_f24.x);
        dilate_3x3_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 1][hipThreadIdx_x8], &sum_f24.y);
        dilate_3x3_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 1][hipThreadIdx_x8], &sum_f24.z);
        dilate_3x3_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 2][hipThreadIdx_x8], &sum_f24.x);
        dilate_3x3_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 2][hipThreadIdx_x8], &sum_f24.y);
        dilate_3x3_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 2][hipThreadIdx_x8], &sum_f24.z);
        rpp_hip_adjust_range(dstPtr, &sum_f24);
        rpp_hip_pack_float24_pln3_and_store24_pln3(dstPtr, dstIdx, dstStridesNCH.y, &sum_f24);
    }
}

// kernelSize = 5
template <typename T>
__global__ void dilate_5x5_pkd3_pln3_tensor(T *srcPtr,
                                            uint2 srcStridesNH,
                                            T *dstPtr,
                                            uint3 dstStridesNCH,
                                            uint padLength,
                                            uint2 tileSize,
                                            RpptROIPtr roiTensorPtrSrc)
{
    int hipThreadIdx_x8 = hipThreadIdx_x << 3;
    int id_x_o = (hipBlockIdx_x * tileSize.x * 8) + hipThreadIdx_x8;
    int id_y_o = hipBlockIdx_y * tileSize.y + hipThreadIdx_y;
    int id_z = hipBlockIdx_z * hipBlockDim_z + hipThreadIdx_z;

    int id_x_i = id_x_o - padLength;
    int id_y_i = id_y_o - padLength;
    d_float24 sum_f24;
    __shared__ uchar src_lds[48][128];

    int srcIdx = (id_z * srcStridesNH.x) + ((id_y_i + roiTensorPtrSrc[id_z].xywhROI.xy.y) * srcStridesNH.y) + ((id_x_i + roiTensorPtrSrc[id_z].xywhROI.xy.x) * 3);
    int dstIdx = (id_z * dstStridesNCH.x) + (id_y_o * dstStridesNCH.z) + id_x_o;
    sum_f24.x.x = (float4) 0;
    sum_f24.x.y = (float4) 0;
    sum_f24.y.x = (float4) 0;
    sum_f24.y.y = (float4) 0;
    sum_f24.z.x = (float4) 0;
    sum_f24.z.y = (float4) 0;

    int3 hipThreadIdx_y_channel;
    hipThreadIdx_y_channel.x = hipThreadIdx_y;
    hipThreadIdx_y_channel.y = hipThreadIdx_y + 16;
    hipThreadIdx_y_channel.z = hipThreadIdx_y + 32;

    uchar *src_lds_channel[3];
    src_lds_channel[0] = &src_lds[hipThreadIdx_y_channel.x][hipThreadIdx_x8];
    src_lds_channel[1] = &src_lds[hipThreadIdx_y_channel.y][hipThreadIdx_x8];
    src_lds_channel[2] = &src_lds[hipThreadIdx_y_channel.z][hipThreadIdx_x8];

    if ((id_x_i >= -(int)padLength) && (id_x_i < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
        (id_y_i >= 0) && (id_y_i < roiTensorPtrSrc[id_z].xywhROI.roiHeight))
    {
        rpp_hip_load24_pkd3_to_uchar8_pln3(srcPtr, srcIdx, src_lds_channel);
    }
    else
    {
        *(uint2 *)src_lds_channel[0] = (uint2)0;
        *(uint2 *)src_lds_channel[1] = (uint2)0;
        *(uint2 *)src_lds_channel[2] = (uint2)0;
    }
    __syncthreads();
    if ((id_x_o < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
        (id_y_o < roiTensorPtrSrc[id_z].xywhROI.roiHeight) &&
        (hipThreadIdx_x < tileSize.x) &&
        (hipThreadIdx_y < tileSize.y))
    {
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x][hipThreadIdx_x8], &sum_f24.x);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y][hipThreadIdx_x8], &sum_f24.y);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z][hipThreadIdx_x8], &sum_f24.z);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 1][hipThreadIdx_x8], &sum_f24.x);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 1][hipThreadIdx_x8], &sum_f24.y);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 1][hipThreadIdx_x8], &sum_f24.z);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 2][hipThreadIdx_x8], &sum_f24.x);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 2][hipThreadIdx_x8], &sum_f24.y);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 2][hipThreadIdx_x8], &sum_f24.z);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 3][hipThreadIdx_x8], &sum_f24.x);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 3][hipThreadIdx_x8], &sum_f24.y);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 3][hipThreadIdx_x8], &sum_f24.z);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 4][hipThreadIdx_x8], &sum_f24.x);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 4][hipThreadIdx_x8], &sum_f24.y);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 4][hipThreadIdx_x8], &sum_f24.z);
        rpp_hip_adjust_range(dstPtr, &sum_f24);
        rpp_hip_pack_float24_pln3_and_store24_pln3(dstPtr, dstIdx, dstStridesNCH.y, &sum_f24);
    }
}

// kernelSize = 7
template <typename T>
__global__ void dilate_7x7_pkd3_pln3_tensor(T *srcPtr,
                                            uint2 srcStridesNH,
                                            T *dstPtr,
                                            uint3 dstStridesNCH,
                                            uint padLength,
                                            uint2 tileSize,
                                            RpptROIPtr roiTensorPtrSrc)
{
    int hipThreadIdx_x8 = hipThreadIdx_x << 3;
    int id_x_o = (hipBlockIdx_x * tileSize.x * 8) + hipThreadIdx_x8;
    int id_y_o = hipBlockIdx_y * tileSize.y + hipThreadIdx_y;
    int id_z = hipBlockIdx_z * hipBlockDim_z + hipThreadIdx_z;

    int id_x_i = id_x_o - padLength;
    int id_y_i = id_y_o - padLength;
    d_float24 sum_f24;
    __shared__ uchar src_lds[48][128];

    int srcIdx = (id_z * srcStridesNH.x) + ((id_y_i + roiTensorPtrSrc[id_z].xywhROI.xy.y) * srcStridesNH.y) + ((id_x_i + roiTensorPtrSrc[id_z].xywhROI.xy.x) * 3);
    int dstIdx = (id_z * dstStridesNCH.x) + (id_y_o * dstStridesNCH.z) + id_x_o;
    sum_f24.x.x = (float4) 0;
    sum_f24.x.y = (float4) 0;
    sum_f24.y.x = (float4) 0;
    sum_f24.y.y = (float4) 0;
    sum_f24.z.x = (float4) 0;
    sum_f24.z.y = (float4) 0;

    int3 hipThreadIdx_y_channel;
    hipThreadIdx_y_channel.x = hipThreadIdx_y;
    hipThreadIdx_y_channel.y = hipThreadIdx_y + 16;
    hipThreadIdx_y_channel.z = hipThreadIdx_y + 32;

    uchar *src_lds_channel[3];
    src_lds_channel[0] = &src_lds[hipThreadIdx_y_channel.x][hipThreadIdx_x8];
    src_lds_channel[1] = &src_lds[hipThreadIdx_y_channel.y][hipThreadIdx_x8];
    src_lds_channel[2] = &src_lds[hipThreadIdx_y_channel.z][hipThreadIdx_x8];

    if ((id_x_i >= -(int)padLength) && (id_x_i < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
        (id_y_i >= 0) && (id_y_i < roiTensorPtrSrc[id_z].xywhROI.roiHeight))
    {
        rpp_hip_load24_pkd3_to_uchar8_pln3(srcPtr, srcIdx, src_lds_channel);
    }
    else
    {
        *(uint2 *)src_lds_channel[0] = (uint2)0;
        *(uint2 *)src_lds_channel[1] = (uint2)0;
        *(uint2 *)src_lds_channel[2] = (uint2)0;
    }
    __syncthreads();
    if ((id_x_o < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
        (id_y_o < roiTensorPtrSrc[id_z].xywhROI.roiHeight) &&
        (hipThreadIdx_x < tileSize.x) &&
        (hipThreadIdx_y < tileSize.y))
    {
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x][hipThreadIdx_x8], &sum_f24.x);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y][hipThreadIdx_x8], &sum_f24.y);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z][hipThreadIdx_x8], &sum_f24.z);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 1][hipThreadIdx_x8], &sum_f24.x);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 1][hipThreadIdx_x8], &sum_f24.y);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 1][hipThreadIdx_x8], &sum_f24.z);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 2][hipThreadIdx_x8], &sum_f24.x);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 2][hipThreadIdx_x8], &sum_f24.y);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 2][hipThreadIdx_x8], &sum_f24.z);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 3][hipThreadIdx_x8], &sum_f24.x);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 3][hipThreadIdx_x8], &sum_f24.y);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 3][hipThreadIdx_x8], &sum_f24.z);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 4][hipThreadIdx_x8], &sum_f24.x);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 4][hipThreadIdx_x8], &sum_f24.y);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 4][hipThreadIdx_x8], &sum_f24.z);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 5][hipThreadIdx_x8], &sum_f24.x);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 5][hipThreadIdx_x8], &sum_f24.y);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 5][hipThreadIdx_x8], &sum_f24.z);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 6][hipThreadIdx_x8], &sum_f24.x);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 6][hipThreadIdx_x8], &sum_f24.y);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 6][hipThreadIdx_x8], &sum_f24.z);
        rpp_hip_adjust_range(dstPtr, &sum_f24);
        rpp_hip_pack_float24_pln3_and_store24_pln3(dstPtr, dstIdx, dstStridesNCH.y, &sum_f24);
    }
}

// kernelSize = 9
template <typename T>
__global__ void dilate_9x9_pkd3_pln3_tensor(T *srcPtr,
                                            uint2 srcStridesNH,
                                            T *dstPtr,
                                            uint3 dstStridesNCH,
                                            uint padLength,
                                            uint2 tileSize,
                                            RpptROIPtr roiTensorPtrSrc)
{
    int hipThreadIdx_x8 = hipThreadIdx_x << 3;
    int id_x_o = (hipBlockIdx_x * tileSize.x * 8) + hipThreadIdx_x8;
    int id_y_o = hipBlockIdx_y * tileSize.y + hipThreadIdx_y;
    int id_z = hipBlockIdx_z * hipBlockDim_z + hipThreadIdx_z;

    int id_x_i = id_x_o - padLength;
    int id_y_i = id_y_o - padLength;
    d_float24 sum_f24;
    __shared__ uchar src_lds[48][128];

    int srcIdx = (id_z * srcStridesNH.x) + ((id_y_i + roiTensorPtrSrc[id_z].xywhROI.xy.y) * srcStridesNH.y) + ((id_x_i + roiTensorPtrSrc[id_z].xywhROI.xy.x) * 3);
    int dstIdx = (id_z * dstStridesNCH.x) + (id_y_o * dstStridesNCH.z) + id_x_o;
    sum_f24.x.x = (float4) 0;
    sum_f24.x.y = (float4) 0;
    sum_f24.y.x = (float4) 0;
    sum_f24.y.y = (float4) 0;
    sum_f24.z.x = (float4) 0;
    sum_f24.z.y = (float4) 0;

    int3 hipThreadIdx_y_channel;
    hipThreadIdx_y_channel.x = hipThreadIdx_y;
    hipThreadIdx_y_channel.y = hipThreadIdx_y + 16;
    hipThreadIdx_y_channel.z = hipThreadIdx_y + 32;

    uchar *src_lds_channel[3];
    src_lds_channel[0] = &src_lds[hipThreadIdx_y_channel.x][hipThreadIdx_x8];
    src_lds_channel[1] = &src_lds[hipThreadIdx_y_channel.y][hipThreadIdx_x8];
    src_lds_channel[2] = &src_lds[hipThreadIdx_y_channel.z][hipThreadIdx_x8];

    if ((id_x_i >= -(int)padLength) && (id_x_i < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
        (id_y_i >= 0) && (id_y_i < roiTensorPtrSrc[id_z].xywhROI.roiHeight))
    {
        rpp_hip_load24_pkd3_to_uchar8_pln3(srcPtr, srcIdx, src_lds_channel);
    }
    else
    {
        *(uint2 *)src_lds_channel[0] = (uint2)0;
        *(uint2 *)src_lds_channel[1] = (uint2)0;
        *(uint2 *)src_lds_channel[2] = (uint2)0;
    }
    __syncthreads();
    if ((id_x_o < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
        (id_y_o < roiTensorPtrSrc[id_z].xywhROI.roiHeight) &&
        (hipThreadIdx_x < tileSize.x) &&
        (hipThreadIdx_y < tileSize.y))
    {
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x][hipThreadIdx_x8], &sum_f24.x);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y][hipThreadIdx_x8], &sum_f24.y);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z][hipThreadIdx_x8], &sum_f24.z);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 1][hipThreadIdx_x8], &sum_f24.x);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 1][hipThreadIdx_x8], &sum_f24.y);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 1][hipThreadIdx_x8], &sum_f24.z);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 2][hipThreadIdx_x8], &sum_f24.x);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 2][hipThreadIdx_x8], &sum_f24.y);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 2][hipThreadIdx_x8], &sum_f24.z);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 3][hipThreadIdx_x8], &sum_f24.x);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 3][hipThreadIdx_x8], &sum_f24.y);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 3][hipThreadIdx_x8], &sum_f24.z);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 4][hipThreadIdx_x8], &sum_f24.x);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 4][hipThreadIdx_x8], &sum_f24.y);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 4][hipThreadIdx_x8], &sum_f24.z);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 5][hipThreadIdx_x8], &sum_f24.x);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 5][hipThreadIdx_x8], &sum_f24.y);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 5][hipThreadIdx_x8], &sum_f24.z);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 6][hipThreadIdx_x8], &sum_f24.x);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 6][hipThreadIdx_x8], &sum_f24.y);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 6][hipThreadIdx_x8], &sum_f24.z);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 7][hipThreadIdx_x8], &sum_f24.x);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 7][hipThreadIdx_x8], &sum_f24.y);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 7][hipThreadIdx_x8], &sum_f24.z);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 8][hipThreadIdx_x8], &sum_f24.x);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 8][hipThreadIdx_x8], &sum_f24.y);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 8][hipThreadIdx_x8], &sum_f24.z);
        rpp_hip_adjust_range(dstPtr, &sum_f24);
        rpp_hip_pack_float24_pln3_and_store24_pln3(dstPtr, dstIdx, dstStridesNCH.y, &sum_f24);
    }
}

// -------------------- Set 4 - PLN3->PKD3 for T = U8/F32/F16/I8 --------------------

// kernelSize = 3
template <typename T>
__global__ void dilate_3x3_pln3_pkd3_tensor(T *srcPtr,
                                            uint3 srcStridesNCH,
                                            T *dstPtr,
                                            uint2 dstStridesNH,
                                            uint padLength,
                                            uint2 tileSize,
                                            RpptROIPtr roiTensorPtrSrc)
{
    int hipThreadIdx_x8 = hipThreadIdx_x << 3;
    int id_x_o = (hipBlockIdx_x * tileSize.x * 8) + hipThreadIdx_x8;
    int id_y_o = hipBlockIdx_y * tileSize.y + hipThreadIdx_y;
    int id_z = hipBlockIdx_z * hipBlockDim_z + hipThreadIdx_z;

    int id_x_i = id_x_o - padLength;
    int id_y_i = id_y_o - padLength;
    d_float24 sum_f24;
    __shared__ uchar src_lds[48][128];

    int3 srcIdx;
    srcIdx.x = (id_z * srcStridesNCH.x) + ((id_y_i + roiTensorPtrSrc[id_z].xywhROI.xy.y) * srcStridesNCH.z) + (id_x_i + roiTensorPtrSrc[id_z].xywhROI.xy.x);
    srcIdx.y = srcIdx.x + srcStridesNCH.y;
    srcIdx.z = srcIdx.y + srcStridesNCH.y;
    int dstIdx = (id_z * dstStridesNH.x) + (id_y_o * dstStridesNH.y) + id_x_o * 3;
    sum_f24.x.x = (float4) 0;
    sum_f24.x.y = (float4) 0;
    sum_f24.y.x = (float4) 0;
    sum_f24.y.y = (float4) 0;
    sum_f24.z.x = (float4) 0;
    sum_f24.z.y = (float4) 0;

    int3 hipThreadIdx_y_channel;
    hipThreadIdx_y_channel.x = hipThreadIdx_y;
    hipThreadIdx_y_channel.y = hipThreadIdx_y + 16;
    hipThreadIdx_y_channel.z = hipThreadIdx_y + 32;

    if ((id_x_i >= -(int)padLength) && (id_x_i < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
        (id_y_i >= 0) && (id_y_i < roiTensorPtrSrc[id_z].xywhROI.roiHeight))
    {
        rpp_hip_load8_to_uchar8(srcPtr, srcIdx.x, &src_lds[hipThreadIdx_y_channel.x][hipThreadIdx_x8]);
        rpp_hip_load8_to_uchar8(srcPtr, srcIdx.y, &src_lds[hipThreadIdx_y_channel.y][hipThreadIdx_x8]);
        rpp_hip_load8_to_uchar8(srcPtr, srcIdx.z, &src_lds[hipThreadIdx_y_channel.z][hipThreadIdx_x8]);
    }
    else
    {
        *(uint2 *)&src_lds[hipThreadIdx_y_channel.x][hipThreadIdx_x8] = (uint2)0;
        *(uint2 *)&src_lds[hipThreadIdx_y_channel.y][hipThreadIdx_x8] = (uint2)0;
        *(uint2 *)&src_lds[hipThreadIdx_y_channel.z][hipThreadIdx_x8] = (uint2)0;
    }
    __syncthreads();
    if ((id_x_o < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
        (id_y_o < roiTensorPtrSrc[id_z].xywhROI.roiHeight) &&
        (hipThreadIdx_x < tileSize.x) &&
        (hipThreadIdx_y < tileSize.y))
    {
        dilate_3x3_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x][hipThreadIdx_x8], &sum_f24.x);
        dilate_3x3_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y][hipThreadIdx_x8], &sum_f24.y);
        dilate_3x3_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z][hipThreadIdx_x8], &sum_f24.z);
        dilate_3x3_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 1][hipThreadIdx_x8], &sum_f24.x);
        dilate_3x3_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 1][hipThreadIdx_x8], &sum_f24.y);
        dilate_3x3_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 1][hipThreadIdx_x8], &sum_f24.z);
        dilate_3x3_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 2][hipThreadIdx_x8], &sum_f24.x);
        dilate_3x3_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 2][hipThreadIdx_x8], &sum_f24.y);
        dilate_3x3_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 2][hipThreadIdx_x8], &sum_f24.z);
        rpp_hip_adjust_range(dstPtr, &sum_f24);
        rpp_hip_pack_float24_pln3_and_store24_pkd3(dstPtr, dstIdx, &sum_f24);
    }
}

// kernelSize = 5
template <typename T>
__global__ void dilate_5x5_pln3_pkd3_tensor(T *srcPtr,
                                            uint3 srcStridesNCH,
                                            T *dstPtr,
                                            uint2 dstStridesNH,
                                            uint padLength,
                                            uint2 tileSize,
                                            RpptROIPtr roiTensorPtrSrc)
{
    int hipThreadIdx_x8 = hipThreadIdx_x << 3;
    int id_x_o = (hipBlockIdx_x * tileSize.x * 8) + hipThreadIdx_x8;
    int id_y_o = hipBlockIdx_y * tileSize.y + hipThreadIdx_y;
    int id_z = hipBlockIdx_z * hipBlockDim_z + hipThreadIdx_z;

    int id_x_i = id_x_o - padLength;
    int id_y_i = id_y_o - padLength;
    d_float24 sum_f24;
    __shared__ uchar src_lds[48][128];

    int3 srcIdx;
    srcIdx.x = (id_z * srcStridesNCH.x) + ((id_y_i + roiTensorPtrSrc[id_z].xywhROI.xy.y) * srcStridesNCH.z) + (id_x_i + roiTensorPtrSrc[id_z].xywhROI.xy.x);
    srcIdx.y = srcIdx.x + srcStridesNCH.y;
    srcIdx.z = srcIdx.y + srcStridesNCH.y;
    int dstIdx = (id_z * dstStridesNH.x) + (id_y_o * dstStridesNH.y) + id_x_o * 3;
    sum_f24.x.x = (float4) 0;
    sum_f24.x.y = (float4) 0;
    sum_f24.y.x = (float4) 0;
    sum_f24.y.y = (float4) 0;
    sum_f24.z.x = (float4) 0;
    sum_f24.z.y = (float4) 0;

    int3 hipThreadIdx_y_channel;
    hipThreadIdx_y_channel.x = hipThreadIdx_y;
    hipThreadIdx_y_channel.y = hipThreadIdx_y + 16;
    hipThreadIdx_y_channel.z = hipThreadIdx_y + 32;

    if ((id_x_i >= -(int)padLength) && (id_x_i < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
        (id_y_i >= 0) && (id_y_i < roiTensorPtrSrc[id_z].xywhROI.roiHeight))
    {
        rpp_hip_load8_to_uchar8(srcPtr, srcIdx.x, &src_lds[hipThreadIdx_y_channel.x][hipThreadIdx_x8]);
        rpp_hip_load8_to_uchar8(srcPtr, srcIdx.y, &src_lds[hipThreadIdx_y_channel.y][hipThreadIdx_x8]);
        rpp_hip_load8_to_uchar8(srcPtr, srcIdx.z, &src_lds[hipThreadIdx_y_channel.z][hipThreadIdx_x8]);
    }
    else
    {
        *(uint2 *)&src_lds[hipThreadIdx_y_channel.x][hipThreadIdx_x8] = (uint2)0;
        *(uint2 *)&src_lds[hipThreadIdx_y_channel.y][hipThreadIdx_x8] = (uint2)0;
        *(uint2 *)&src_lds[hipThreadIdx_y_channel.z][hipThreadIdx_x8] = (uint2)0;
    }
    __syncthreads();
    if ((id_x_o < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
        (id_y_o < roiTensorPtrSrc[id_z].xywhROI.roiHeight) &&
        (hipThreadIdx_x < tileSize.x) &&
        (hipThreadIdx_y < tileSize.y))
    {
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x][hipThreadIdx_x8], &sum_f24.x);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y][hipThreadIdx_x8], &sum_f24.y);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z][hipThreadIdx_x8], &sum_f24.z);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 1][hipThreadIdx_x8], &sum_f24.x);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 1][hipThreadIdx_x8], &sum_f24.y);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 1][hipThreadIdx_x8], &sum_f24.z);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 2][hipThreadIdx_x8], &sum_f24.x);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 2][hipThreadIdx_x8], &sum_f24.y);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 2][hipThreadIdx_x8], &sum_f24.z);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 3][hipThreadIdx_x8], &sum_f24.x);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 3][hipThreadIdx_x8], &sum_f24.y);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 3][hipThreadIdx_x8], &sum_f24.z);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 4][hipThreadIdx_x8], &sum_f24.x);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 4][hipThreadIdx_x8], &sum_f24.y);
        dilate_5x5_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 4][hipThreadIdx_x8], &sum_f24.z);
        rpp_hip_adjust_range(dstPtr, &sum_f24);
        rpp_hip_pack_float24_pln3_and_store24_pkd3(dstPtr, dstIdx, &sum_f24);
    }
}

// kernelSize = 7
template <typename T>
__global__ void dilate_7x7_pln3_pkd3_tensor(T *srcPtr,
                                            uint3 srcStridesNCH,
                                            T *dstPtr,
                                            uint2 dstStridesNH,
                                            uint padLength,
                                            uint2 tileSize,
                                            RpptROIPtr roiTensorPtrSrc)
{
    int hipThreadIdx_x8 = hipThreadIdx_x << 3;
    int id_x_o = (hipBlockIdx_x * tileSize.x * 8) + hipThreadIdx_x8;
    int id_y_o = hipBlockIdx_y * tileSize.y + hipThreadIdx_y;
    int id_z = hipBlockIdx_z * hipBlockDim_z + hipThreadIdx_z;

    int id_x_i = id_x_o - padLength;
    int id_y_i = id_y_o - padLength;
    d_float24 sum_f24;
    __shared__ uchar src_lds[48][128];

    int3 srcIdx;
    srcIdx.x = (id_z * srcStridesNCH.x) + ((id_y_i + roiTensorPtrSrc[id_z].xywhROI.xy.y) * srcStridesNCH.z) + (id_x_i + roiTensorPtrSrc[id_z].xywhROI.xy.x);
    srcIdx.y = srcIdx.x + srcStridesNCH.y;
    srcIdx.z = srcIdx.y + srcStridesNCH.y;
    int dstIdx = (id_z * dstStridesNH.x) + (id_y_o * dstStridesNH.y) + id_x_o * 3;
    sum_f24.x.x = (float4) 0;
    sum_f24.x.y = (float4) 0;
    sum_f24.y.x = (float4) 0;
    sum_f24.y.y = (float4) 0;
    sum_f24.z.x = (float4) 0;
    sum_f24.z.y = (float4) 0;

    int3 hipThreadIdx_y_channel;
    hipThreadIdx_y_channel.x = hipThreadIdx_y;
    hipThreadIdx_y_channel.y = hipThreadIdx_y + 16;
    hipThreadIdx_y_channel.z = hipThreadIdx_y + 32;

    if ((id_x_i >= -(int)padLength) && (id_x_i < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
        (id_y_i >= 0) && (id_y_i < roiTensorPtrSrc[id_z].xywhROI.roiHeight))
    {
        rpp_hip_load8_to_uchar8(srcPtr, srcIdx.x, &src_lds[hipThreadIdx_y_channel.x][hipThreadIdx_x8]);
        rpp_hip_load8_to_uchar8(srcPtr, srcIdx.y, &src_lds[hipThreadIdx_y_channel.y][hipThreadIdx_x8]);
        rpp_hip_load8_to_uchar8(srcPtr, srcIdx.z, &src_lds[hipThreadIdx_y_channel.z][hipThreadIdx_x8]);
    }
    else
    {
        *(uint2 *)&src_lds[hipThreadIdx_y_channel.x][hipThreadIdx_x8] = (uint2)0;
        *(uint2 *)&src_lds[hipThreadIdx_y_channel.y][hipThreadIdx_x8] = (uint2)0;
        *(uint2 *)&src_lds[hipThreadIdx_y_channel.z][hipThreadIdx_x8] = (uint2)0;
    }
    __syncthreads();
    if ((id_x_o < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
        (id_y_o < roiTensorPtrSrc[id_z].xywhROI.roiHeight) &&
        (hipThreadIdx_x < tileSize.x) &&
        (hipThreadIdx_y < tileSize.y))
    {
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x][hipThreadIdx_x8], &sum_f24.x);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y][hipThreadIdx_x8], &sum_f24.y);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z][hipThreadIdx_x8], &sum_f24.z);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 1][hipThreadIdx_x8], &sum_f24.x);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 1][hipThreadIdx_x8], &sum_f24.y);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 1][hipThreadIdx_x8], &sum_f24.z);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 2][hipThreadIdx_x8], &sum_f24.x);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 2][hipThreadIdx_x8], &sum_f24.y);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 2][hipThreadIdx_x8], &sum_f24.z);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 3][hipThreadIdx_x8], &sum_f24.x);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 3][hipThreadIdx_x8], &sum_f24.y);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 3][hipThreadIdx_x8], &sum_f24.z);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 4][hipThreadIdx_x8], &sum_f24.x);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 4][hipThreadIdx_x8], &sum_f24.y);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 4][hipThreadIdx_x8], &sum_f24.z);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 5][hipThreadIdx_x8], &sum_f24.x);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 5][hipThreadIdx_x8], &sum_f24.y);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 5][hipThreadIdx_x8], &sum_f24.z);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 6][hipThreadIdx_x8], &sum_f24.x);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 6][hipThreadIdx_x8], &sum_f24.y);
        dilate_7x7_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 6][hipThreadIdx_x8], &sum_f24.z);
        rpp_hip_adjust_range(dstPtr, &sum_f24);
        rpp_hip_pack_float24_pln3_and_store24_pkd3(dstPtr, dstIdx, &sum_f24);
    }
}

// kernelSize = 9
template <typename T>
__global__ void dilate_9x9_pln3_pkd3_tensor(T *srcPtr,
                                            uint3 srcStridesNCH,
                                            T *dstPtr,
                                            uint2 dstStridesNH,
                                            uint padLength,
                                            uint2 tileSize,
                                            RpptROIPtr roiTensorPtrSrc)
{
    int hipThreadIdx_x8 = hipThreadIdx_x << 3;
    int id_x_o = (hipBlockIdx_x * tileSize.x * 8) + hipThreadIdx_x8;
    int id_y_o = hipBlockIdx_y * tileSize.y + hipThreadIdx_y;
    int id_z = hipBlockIdx_z * hipBlockDim_z + hipThreadIdx_z;

    int id_x_i = id_x_o - padLength;
    int id_y_i = id_y_o - padLength;
    d_float24 sum_f24;
    __shared__ uchar src_lds[48][128];

    int3 srcIdx;
    srcIdx.x = (id_z * srcStridesNCH.x) + ((id_y_i + roiTensorPtrSrc[id_z].xywhROI.xy.y) * srcStridesNCH.z) + (id_x_i + roiTensorPtrSrc[id_z].xywhROI.xy.x);
    srcIdx.y = srcIdx.x + srcStridesNCH.y;
    srcIdx.z = srcIdx.y + srcStridesNCH.y;
    int dstIdx = (id_z * dstStridesNH.x) + (id_y_o * dstStridesNH.y) + id_x_o * 3;
    sum_f24.x.x = (float4) 0;
    sum_f24.x.y = (float4) 0;
    sum_f24.y.x = (float4) 0;
    sum_f24.y.y = (float4) 0;
    sum_f24.z.x = (float4) 0;
    sum_f24.z.y = (float4) 0;

    int3 hipThreadIdx_y_channel;
    hipThreadIdx_y_channel.x = hipThreadIdx_y;
    hipThreadIdx_y_channel.y = hipThreadIdx_y + 16;
    hipThreadIdx_y_channel.z = hipThreadIdx_y + 32;

    if ((id_x_i >= -(int)padLength) && (id_x_i < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
        (id_y_i >= 0) && (id_y_i < roiTensorPtrSrc[id_z].xywhROI.roiHeight))
    {
        rpp_hip_load8_to_uchar8(srcPtr, srcIdx.x, &src_lds[hipThreadIdx_y_channel.x][hipThreadIdx_x8]);
        rpp_hip_load8_to_uchar8(srcPtr, srcIdx.y, &src_lds[hipThreadIdx_y_channel.y][hipThreadIdx_x8]);
        rpp_hip_load8_to_uchar8(srcPtr, srcIdx.z, &src_lds[hipThreadIdx_y_channel.z][hipThreadIdx_x8]);
    }
    else
    {
        *(uint2 *)&src_lds[hipThreadIdx_y_channel.x][hipThreadIdx_x8] = (uint2)0;
        *(uint2 *)&src_lds[hipThreadIdx_y_channel.y][hipThreadIdx_x8] = (uint2)0;
        *(uint2 *)&src_lds[hipThreadIdx_y_channel.z][hipThreadIdx_x8] = (uint2)0;
    }
    __syncthreads();
    if ((id_x_o < roiTensorPtrSrc[id_z].xywhROI.roiWidth) &&
        (id_y_o < roiTensorPtrSrc[id_z].xywhROI.roiHeight) &&
        (hipThreadIdx_x < tileSize.x) &&
        (hipThreadIdx_y < tileSize.y))
    {
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x][hipThreadIdx_x8], &sum_f24.x);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y][hipThreadIdx_x8], &sum_f24.y);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z][hipThreadIdx_x8], &sum_f24.z);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 1][hipThreadIdx_x8], &sum_f24.x);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 1][hipThreadIdx_x8], &sum_f24.y);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 1][hipThreadIdx_x8], &sum_f24.z);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 2][hipThreadIdx_x8], &sum_f24.x);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 2][hipThreadIdx_x8], &sum_f24.y);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 2][hipThreadIdx_x8], &sum_f24.z);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 3][hipThreadIdx_x8], &sum_f24.x);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 3][hipThreadIdx_x8], &sum_f24.y);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 3][hipThreadIdx_x8], &sum_f24.z);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 4][hipThreadIdx_x8], &sum_f24.x);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 4][hipThreadIdx_x8], &sum_f24.y);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 4][hipThreadIdx_x8], &sum_f24.z);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 5][hipThreadIdx_x8], &sum_f24.x);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 5][hipThreadIdx_x8], &sum_f24.y);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 5][hipThreadIdx_x8], &sum_f24.z);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 6][hipThreadIdx_x8], &sum_f24.x);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 6][hipThreadIdx_x8], &sum_f24.y);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 6][hipThreadIdx_x8], &sum_f24.z);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 7][hipThreadIdx_x8], &sum_f24.x);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 7][hipThreadIdx_x8], &sum_f24.y);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 7][hipThreadIdx_x8], &sum_f24.z);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.x + 8][hipThreadIdx_x8], &sum_f24.x);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.y + 8][hipThreadIdx_x8], &sum_f24.y);
        dilate_9x9_row_hip_compute(&src_lds[hipThreadIdx_y_channel.z + 8][hipThreadIdx_x8], &sum_f24.z);
        rpp_hip_adjust_range(dstPtr, &sum_f24);
        rpp_hip_pack_float24_pln3_and_store24_pkd3(dstPtr, dstIdx, &sum_f24);
    }
}

// -------------------- Set 5 - Kernel Executors --------------------

template <typename T>
RppStatus hip_exec_dilate_tensor(T *srcPtr,
                                 RpptDescPtr srcDescPtr,
                                 T *dstPtr,
                                 RpptDescPtr dstDescPtr,
                                 Rpp32u kernelSize,
                                 RpptROIPtr roiTensorPtrSrc,
                                 RpptRoiType roiType,
                                 rpp::Handle& handle)
{
    if (roiType == RpptRoiType::LTRB)
        hip_exec_roi_converison_ltrb_to_xywh(roiTensorPtrSrc, handle);

    int localThreads_x = LOCAL_THREADS_X;
    int localThreads_y = LOCAL_THREADS_Y;
    int localThreads_z = LOCAL_THREADS_Z;
    int globalThreads_x = (dstDescPtr->strides.hStride + 7) >> 3;
    int globalThreads_y = dstDescPtr->h;
    int globalThreads_z = handle.GetBatchSize();

    uint padLength = kernelSize / 2;
    uint padLengthTwice = padLength * 2;
    uint2 tileSize;
    tileSize.x = (128 - padLengthTwice) / 8;
    tileSize.y = 16 - padLengthTwice;

    if ((srcDescPtr->layout == RpptLayout::NHWC) && (dstDescPtr->layout == RpptLayout::NHWC))
    {
        globalThreads_x = (dstDescPtr->strides.hStride / 3 + 7) >> 3;

        if (kernelSize == 3)
        {
            hipLaunchKernelGGL(dilate_3x3_pkd_tensor,
                               dim3(ceil((float)globalThreads_x/tileSize.x), ceil((float)globalThreads_y/tileSize.y), ceil((float)globalThreads_z/localThreads_z)),
                               dim3(localThreads_x, localThreads_y, localThreads_z),
                               0,
                               handle.GetStream(),
                               srcPtr,
                               make_uint2(srcDescPtr->strides.nStride, srcDescPtr->strides.hStride),
                               dstPtr,
                               make_uint2(dstDescPtr->strides.nStride, dstDescPtr->strides.hStride),
                               padLength,
                               tileSize,
                               roiTensorPtrSrc);
        }
        else if (kernelSize == 5)
        {
            hipLaunchKernelGGL(dilate_5x5_pkd_tensor,
                               dim3(ceil((float)globalThreads_x/tileSize.x), ceil((float)globalThreads_y/tileSize.y), ceil((float)globalThreads_z/localThreads_z)),
                               dim3(localThreads_x, localThreads_y, localThreads_z),
                               0,
                               handle.GetStream(),
                               srcPtr,
                               make_uint2(srcDescPtr->strides.nStride, srcDescPtr->strides.hStride),
                               dstPtr,
                               make_uint2(dstDescPtr->strides.nStride, dstDescPtr->strides.hStride),
                               padLength,
                               tileSize,
                               roiTensorPtrSrc);
        }
        else if (kernelSize == 7)
        {
            hipLaunchKernelGGL(dilate_7x7_pkd_tensor,
                               dim3(ceil((float)globalThreads_x/tileSize.x), ceil((float)globalThreads_y/tileSize.y), ceil((float)globalThreads_z/localThreads_z)),
                               dim3(localThreads_x, localThreads_y, localThreads_z),
                               0,
                               handle.GetStream(),
                               srcPtr,
                               make_uint2(srcDescPtr->strides.nStride, srcDescPtr->strides.hStride),
                               dstPtr,
                               make_uint2(dstDescPtr->strides.nStride, dstDescPtr->strides.hStride),
                               padLength,
                               tileSize,
                               roiTensorPtrSrc);
        }
        else if (kernelSize == 9)
        {
            hipLaunchKernelGGL(dilate_9x9_pkd_tensor,
                               dim3(ceil((float)globalThreads_x/tileSize.x), ceil((float)globalThreads_y/tileSize.y), ceil((float)globalThreads_z/localThreads_z)),
                               dim3(localThreads_x, localThreads_y, localThreads_z),
                               0,
                               handle.GetStream(),
                               srcPtr,
                               make_uint2(srcDescPtr->strides.nStride, srcDescPtr->strides.hStride),
                               dstPtr,
                               make_uint2(dstDescPtr->strides.nStride, dstDescPtr->strides.hStride),
                               padLength,
                               tileSize,
                               roiTensorPtrSrc);
        }
    }
    else if ((srcDescPtr->layout == RpptLayout::NCHW) && (dstDescPtr->layout == RpptLayout::NCHW))
    {
        if (kernelSize == 3)
        {
            hipLaunchKernelGGL(dilate_3x3_pln_tensor,
                               dim3(ceil((float)globalThreads_x/tileSize.x), ceil((float)globalThreads_y/tileSize.y), ceil((float)globalThreads_z/localThreads_z)),
                               dim3(localThreads_x, localThreads_y, localThreads_z),
                               0,
                               handle.GetStream(),
                               srcPtr,
                               make_uint3(srcDescPtr->strides.nStride, srcDescPtr->strides.cStride, srcDescPtr->strides.hStride),
                               dstPtr,
                               make_uint3(dstDescPtr->strides.nStride, dstDescPtr->strides.cStride, dstDescPtr->strides.hStride),
                               dstDescPtr->c,
                               padLength,
                               tileSize,
                               roiTensorPtrSrc);
        }
        else if (kernelSize == 5)
        {
            hipLaunchKernelGGL(dilate_5x5_pln_tensor,
                               dim3(ceil((float)globalThreads_x/tileSize.x), ceil((float)globalThreads_y/tileSize.y), ceil((float)globalThreads_z/localThreads_z)),
                               dim3(localThreads_x, localThreads_y, localThreads_z),
                               0,
                               handle.GetStream(),
                               srcPtr,
                               make_uint3(srcDescPtr->strides.nStride, srcDescPtr->strides.cStride, srcDescPtr->strides.hStride),
                               dstPtr,
                               make_uint3(dstDescPtr->strides.nStride, dstDescPtr->strides.cStride, dstDescPtr->strides.hStride),
                               dstDescPtr->c,
                               padLength,
                               tileSize,
                               roiTensorPtrSrc);
        }
        else if (kernelSize == 7)
        {
            hipLaunchKernelGGL(dilate_7x7_pln_tensor,
                               dim3(ceil((float)globalThreads_x/tileSize.x), ceil((float)globalThreads_y/tileSize.y), ceil((float)globalThreads_z/localThreads_z)),
                               dim3(localThreads_x, localThreads_y, localThreads_z),
                               0,
                               handle.GetStream(),
                               srcPtr,
                               make_uint3(srcDescPtr->strides.nStride, srcDescPtr->strides.cStride, srcDescPtr->strides.hStride),
                               dstPtr,
                               make_uint3(dstDescPtr->strides.nStride, dstDescPtr->strides.cStride, dstDescPtr->strides.hStride),
                               dstDescPtr->c,
                               padLength,
                               tileSize,
                               roiTensorPtrSrc);
        }
        else if (kernelSize == 9)
        {
            hipLaunchKernelGGL(dilate_9x9_pln_tensor,
                               dim3(ceil((float)globalThreads_x/tileSize.x), ceil((float)globalThreads_y/tileSize.y), ceil((float)globalThreads_z/localThreads_z)),
                               dim3(localThreads_x, localThreads_y, localThreads_z),
                               0,
                               handle.GetStream(),
                               srcPtr,
                               make_uint3(srcDescPtr->strides.nStride, srcDescPtr->strides.cStride, srcDescPtr->strides.hStride),
                               dstPtr,
                               make_uint3(dstDescPtr->strides.nStride, dstDescPtr->strides.cStride, dstDescPtr->strides.hStride),
                               dstDescPtr->c,
                               padLength,
                               tileSize,
                               roiTensorPtrSrc);
        }
    }
    else if ((srcDescPtr->c == 3) && (dstDescPtr->c == 3))
    {
        if ((srcDescPtr->layout == RpptLayout::NHWC) && (dstDescPtr->layout == RpptLayout::NCHW))
        {
            if (kernelSize == 3)
            {
                hipLaunchKernelGGL(dilate_3x3_pkd3_pln3_tensor,
                                   dim3(ceil((float)globalThreads_x/tileSize.x), ceil((float)globalThreads_y/tileSize.y), ceil((float)globalThreads_z/localThreads_z)),
                                   dim3(localThreads_x, localThreads_y, localThreads_z),
                                   0,
                                   handle.GetStream(),
                                   srcPtr,
                                   make_uint2(srcDescPtr->strides.nStride, srcDescPtr->strides.hStride),
                                   dstPtr,
                                   make_uint3(dstDescPtr->strides.nStride, dstDescPtr->strides.cStride, dstDescPtr->strides.hStride),
                                   padLength,
                                   tileSize,
                                   roiTensorPtrSrc);
            }
            else if (kernelSize == 5)
            {
                hipLaunchKernelGGL(dilate_5x5_pkd3_pln3_tensor,
                                   dim3(ceil((float)globalThreads_x/tileSize.x), ceil((float)globalThreads_y/tileSize.y), ceil((float)globalThreads_z/localThreads_z)),
                                   dim3(localThreads_x, localThreads_y, localThreads_z),
                                   0,
                                   handle.GetStream(),
                                   srcPtr,
                                   make_uint2(srcDescPtr->strides.nStride, srcDescPtr->strides.hStride),
                                   dstPtr,
                                   make_uint3(dstDescPtr->strides.nStride, dstDescPtr->strides.cStride, dstDescPtr->strides.hStride),
                                   padLength,
                                   tileSize,
                                   roiTensorPtrSrc);
            }
            else if (kernelSize == 7)
            {
                hipLaunchKernelGGL(dilate_7x7_pkd3_pln3_tensor,
                                   dim3(ceil((float)globalThreads_x/tileSize.x), ceil((float)globalThreads_y/tileSize.y), ceil((float)globalThreads_z/localThreads_z)),
                                   dim3(localThreads_x, localThreads_y, localThreads_z),
                                   0,
                                   handle.GetStream(),
                                   srcPtr,
                                   make_uint2(srcDescPtr->strides.nStride, srcDescPtr->strides.hStride),
                                   dstPtr,
                                   make_uint3(dstDescPtr->strides.nStride, dstDescPtr->strides.cStride, dstDescPtr->strides.hStride),
                                   padLength,
                                   tileSize,
                                   roiTensorPtrSrc);
            }
            else if (kernelSize == 9)
            {
                hipLaunchKernelGGL(dilate_9x9_pkd3_pln3_tensor,
                                   dim3(ceil((float)globalThreads_x/tileSize.x), ceil((float)globalThreads_y/tileSize.y), ceil((float)globalThreads_z/localThreads_z)),
                                   dim3(localThreads_x, localThreads_y, localThreads_z),
                                   0,
                                   handle.GetStream(),
                                   srcPtr,
                                   make_uint2(srcDescPtr->strides.nStride, srcDescPtr->strides.hStride),
                                   dstPtr,
                                   make_uint3(dstDescPtr->strides.nStride, dstDescPtr->strides.cStride, dstDescPtr->strides.hStride),
                                   padLength,
                                   tileSize,
                                   roiTensorPtrSrc);
            }
        }
        else if ((srcDescPtr->layout == RpptLayout::NCHW) && (dstDescPtr->layout == RpptLayout::NHWC))
        {
            globalThreads_x = (srcDescPtr->strides.hStride + 7) >> 3;

            if (kernelSize == 3)
            {
                hipLaunchKernelGGL(dilate_3x3_pln3_pkd3_tensor,
                                   dim3(ceil((float)globalThreads_x/tileSize.x), ceil((float)globalThreads_y/tileSize.y), ceil((float)globalThreads_z/localThreads_z)),
                                   dim3(localThreads_x, localThreads_y, localThreads_z),
                                   0,
                                   handle.GetStream(),
                                   srcPtr,
                                   make_uint3(srcDescPtr->strides.nStride, srcDescPtr->strides.cStride, srcDescPtr->strides.hStride),
                                   dstPtr,
                                   make_uint2(dstDescPtr->strides.nStride, dstDescPtr->strides.hStride),
                                   padLength,
                                   tileSize,
                                   roiTensorPtrSrc);
            }
            else if (kernelSize == 5)
            {
                hipLaunchKernelGGL(dilate_5x5_pln3_pkd3_tensor,
                                   dim3(ceil((float)globalThreads_x/tileSize.x), ceil((float)globalThreads_y/tileSize.y), ceil((float)globalThreads_z/localThreads_z)),
                                   dim3(localThreads_x, localThreads_y, localThreads_z),
                                   0,
                                   handle.GetStream(),
                                   srcPtr,
                                   make_uint3(srcDescPtr->strides.nStride, srcDescPtr->strides.cStride, srcDescPtr->strides.hStride),
                                   dstPtr,
                                   make_uint2(dstDescPtr->strides.nStride, dstDescPtr->strides.hStride),
                                   padLength,
                                   tileSize,
                                   roiTensorPtrSrc);
            }
            else if (kernelSize == 7)
            {
                hipLaunchKernelGGL(dilate_7x7_pln3_pkd3_tensor,
                                   dim3(ceil((float)globalThreads_x/tileSize.x), ceil((float)globalThreads_y/tileSize.y), ceil((float)globalThreads_z/localThreads_z)),
                                   dim3(localThreads_x, localThreads_y, localThreads_z),
                                   0,
                                   handle.GetStream(),
                                   srcPtr,
                                   make_uint3(srcDescPtr->strides.nStride, srcDescPtr->strides.cStride, srcDescPtr->strides.hStride),
                                   dstPtr,
                                   make_uint2(dstDescPtr->strides.nStride, dstDescPtr->strides.hStride),
                                   padLength,
                                   tileSize,
                                   roiTensorPtrSrc);
            }
            else if (kernelSize == 9)
            {
                hipLaunchKernelGGL(dilate_9x9_pln3_pkd3_tensor,
                                   dim3(ceil((float)globalThreads_x/tileSize.x), ceil((float)globalThreads_y/tileSize.y), ceil((float)globalThreads_z/localThreads_z)),
                                   dim3(localThreads_x, localThreads_y, localThreads_z),
                                   0,
                                   handle.GetStream(),
                                   srcPtr,
                                   make_uint3(srcDescPtr->strides.nStride, srcDescPtr->strides.cStride, srcDescPtr->strides.hStride),
                                   dstPtr,
                                   make_uint2(dstDescPtr->strides.nStride, dstDescPtr->strides.hStride),
                                   padLength,
                                   tileSize,
                                   roiTensorPtrSrc);
            }
        }
    }

    return RPP_SUCCESS;
}
