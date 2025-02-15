#ifndef AMD_RPP_RPP_CPU_SIMD_HPP
#define AMD_RPP_RPP_CPU_SIMD_HPP

#include "stdio.h"
#include "rppdefs.h"

#if _WIN32
#include <intrin.h>
#else
#include <x86intrin.h>
#include <smmintrin.h>
#include <immintrin.h>
#endif

#define __AVX2__ 1
#define __SSE4_1__ 1

#define M256I(m256i_register) (*((_m256i_union*)&m256i_register))
typedef union
{
    char m256i_i8[32];
    short m256i_i16[16];
    int m256i_i32[8];
    long long m256i_i64[4];
    __m128i m256i_i128[2];
} _m256i_union;

#if defined(_MSC_VER)
#define SIMD_ALIGN_VAR(type, name, alignment) \
    __declspec(align(alignment)) type name
#else
#define SIMD_ALIGN_VAR(type, name, alignment) \
    type __attribute__((__aligned__(alignment))) name
#endif // _MSC_VER

#define SIMD_CONST_PI(name, val0, val1, val2, val3) \
    SIMD_ALIGN_VAR(static const int, _xmm_const_##name[4], 16) = { \
        static_cast<int>(val3), \
        static_cast<int>(val2), \
        static_cast<int>(val1), \
        static_cast<int>(val0)  \
    }

#define SIMD_CONST_PS(name, val0, val1, val2, val3) \
    SIMD_ALIGN_VAR(static const float, _xmm_const_##name[4], 16) = { \
        static_cast<float>(val3), \
        static_cast<float>(val2), \
        static_cast<float>(val1), \
        static_cast<float>(val0)  \
    }

#define SIMD_GET_PS(name) (*(const __m128  *)_xmm_const_##name)

const __m128 xmm_p0 = _mm_set1_ps(0.0f);
const __m128 xmm_p1 = _mm_set1_ps(1.0f);
const __m128 xmm_p2 = _mm_set1_ps(2.0f);
const __m128 xmm_p4 = _mm_set1_ps(4.0f);
const __m128 xmm_p6 = _mm_set1_ps(6.0f);
const __m128 xmm_p16 = _mm_set1_ps(16.0f);
const __m128 xmm_p255 = _mm_set1_ps(255.0f);
const __m128 xmm_p1op255 = _mm_set1_ps(1.0f / 255.0f);
const __m128 xmm_p1op3 = _mm_set1_ps(1.0f / 3.0f);
const __m128 xmm_p2op3 = _mm_set1_ps(2.0f / 3.0f);
const __m128i xmm_px0 = _mm_set1_epi32(0);
const __m128i xmm_px1 = _mm_set1_epi32(1);
const __m128i xmm_px2 = _mm_set1_epi32(2);
const __m128i xmm_px3 = _mm_set1_epi32(3);
const __m128i xmm_px4 = _mm_set1_epi32(4);
const __m128i xmm_px5 = _mm_set1_epi32(5);

const __m256 avx_p0 = _mm256_set1_ps(0.0f);
const __m256 avx_p1 = _mm256_set1_ps(1.0f);
const __m256 avx_p2 = _mm256_set1_ps(2.0f);
const __m256 avx_p4 = _mm256_set1_ps(4.0f);
const __m256 avx_p6 = _mm256_set1_ps(6.0f);
const __m256 avx_p255 = _mm256_set1_ps(255.0f);
const __m256 avx_p1op255 = _mm256_set1_ps(1.0f / 255.0f);
const __m256 avx_p1op3 = _mm256_set1_ps(1.0f / 3.0f);
const __m256 avx_p2op3 = _mm256_set1_ps(2.0f / 3.0f);
const __m256i avx_px0 = _mm256_set1_epi32(0);
const __m256i avx_px1 = _mm256_set1_epi32(1);
const __m256i avx_px2 = _mm256_set1_epi32(2);
const __m256i avx_px3 = _mm256_set1_epi32(3);
const __m256i avx_px4 = _mm256_set1_epi32(4);
const __m256i avx_px5 = _mm256_set1_epi32(5);

const __m128i pxMask0 = _mm_setr_epi8(0, 0x80, 0x80, 0x80, 1, 0x80, 0x80, 0x80, 2, 0x80, 0x80, 0x80, 3, 0x80, 0x80, 0x80);
const __m128i pxMask1 = _mm_setr_epi8(4, 0x80, 0x80, 0x80, 5, 0x80, 0x80, 0x80, 6, 0x80, 0x80, 0x80, 7, 0x80, 0x80, 0x80);
const __m128i pxMask2 = _mm_setr_epi8(8, 0x80, 0x80, 0x80, 9, 0x80, 0x80, 0x80, 10, 0x80, 0x80, 0x80, 11, 0x80, 0x80, 0x80);
const __m128i pxMask3 = _mm_setr_epi8(12, 0x80, 0x80, 0x80, 13, 0x80, 0x80, 0x80, 14, 0x80, 0x80, 0x80, 15, 0x80, 0x80, 0x80);

// Print helpers

inline void rpp_mm_print_epi8(__m128i vPrintArray)
{
    char printArray[16];
    _mm_storeu_si128((__m128i *)printArray, vPrintArray);
    printf("\n");
    for (int ct = 0; ct < 16; ct++)
    {
        printf("%d ", printArray[ct]);
    }
}

inline void rpp_mm_print_epi32(__m128i vPrintArray)
{
    int printArray[4];
    _mm_storeu_si128((__m128i *)printArray, vPrintArray);
    printf("\n");
    for (int ct = 0; ct < 4; ct++)
    {
        printf("%d ", printArray[ct]);
    }
}

inline void rpp_mm_print_ps(__m128 vPrintArray)
{
    float printArray[4];
    _mm_storeu_ps(printArray, vPrintArray);
    printf("\n");
    for (int ct = 0; ct < 4; ct++)
    {
        printf("%0.6f ", printArray[ct]);
    }
}

inline void rpp_mm256_print_epi8(__m256i vPrintArray)
{
    unsigned char printArray[32];
    _mm256_storeu_si256((__m256i *)printArray, vPrintArray);
    printf("\n");
    for (int ct = 0; ct < 32; ct++)
    {
        printf("%d ", printArray[ct]);
    }
}

inline void rpp_mm256_print_epi32(__m256i vPrintArray)
{
    int printArray[8];
    _mm256_storeu_si256((__m256i *)printArray, vPrintArray);
    printf("\n");
    for (int ct = 0; ct < 8; ct++)
    {
        printf("%d ", printArray[ct]);
    }
}

inline void rpp_mm256_print_ps(__m256 vPrintArray)
{
    float printArray[8];
    _mm256_storeu_ps(printArray, vPrintArray);
    printf("\n");
    for (int ct = 0; ct < 8; ct++)
    {
        printf("%0.6f ", printArray[ct]);
    }
}

// SSE loads and stores

inline RppStatus rpp_load48_u8pkd3_to_f32pln3(Rpp8u *srcPtr, __m128 *p)
{
    __m128i px[4];
    __m128i maskR = _mm_setr_epi8(0, 0x80, 0x80, 0x80, 3, 0x80, 0x80, 0x80, 6, 0x80, 0x80, 0x80, 9, 0x80, 0x80, 0x80);
    __m128i maskG = _mm_setr_epi8(1, 0x80, 0x80, 0x80, 4, 0x80, 0x80, 0x80, 7, 0x80, 0x80, 0x80, 10, 0x80, 0x80, 0x80);
    __m128i maskB = _mm_setr_epi8(2, 0x80, 0x80, 0x80, 5, 0x80, 0x80, 0x80, 8, 0x80, 0x80, 0x80, 11, 0x80, 0x80, 0x80);
    px[0] = _mm_loadu_si128((__m128i *)srcPtr);           /* load [R01|G01|B01|R02|G02|B02|R03|G03|B03|R04|G04|B04|R05|G05|B05|R06] - Need RGB 01-04 */
    px[1] = _mm_loadu_si128((__m128i *)(srcPtr + 12));    /* load [R05|G05|B05|R06|G06|B06|R07|G07|B07|R08|G08|B08|R09|G09|B09|R10] - Need RGB 05-08 */
    px[2] = _mm_loadu_si128((__m128i *)(srcPtr + 24));    /* load [R09|G09|B09|R10|G10|B10|R11|G11|B11|R12|G12|B12|R13|G13|B13|R14] - Need RGB 09-12 */
    px[3] = _mm_loadu_si128((__m128i *)(srcPtr + 36));    /* load [R13|G13|B13|R14|G14|B14|R15|G15|B15|R16|G16|B16|R17|G17|B17|R18] - Need RGB 13-16 */
    p[0] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[0], maskR));    /* Contains R01-04 */
    p[1] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[1], maskR));    /* Contains R05-08 */
    p[2] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[2], maskR));    /* Contains R09-12 */
    p[3] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[3], maskR));    /* Contains R13-16 */
    p[4] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[0], maskG));    /* Contains G01-04 */
    p[5] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[1], maskG));    /* Contains G05-08 */
    p[6] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[2], maskG));    /* Contains G09-12 */
    p[7] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[3], maskG));    /* Contains G13-16 */
    p[8] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[0], maskB));    /* Contains B01-04 */
    p[9] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[1], maskB));    /* Contains B05-08 */
    p[10] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[2], maskB));    /* Contains B09-12 */
    p[11] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[3], maskB));    /* Contains B13-16 */

    return RPP_SUCCESS;
}

inline RppStatus rpp_store48_f32pln3_to_u8pln3(Rpp8u *dstPtrR, Rpp8u *dstPtrG, Rpp8u *dstPtrB, __m128 *p)
{
    __m128i px[8];

    px[4] = _mm_cvtps_epi32(p[0]);    /* convert to int32 for R */
    px[5] = _mm_cvtps_epi32(p[1]);    /* convert to int32 for R */
    px[6] = _mm_cvtps_epi32(p[2]);    /* convert to int32 for R */
    px[7] = _mm_cvtps_epi32(p[3]);    /* convert to int32 for R */
    px[4] = _mm_packus_epi32(px[4], px[5]);    /* pack pixels 0-7 for R */
    px[5] = _mm_packus_epi32(px[6], px[7]);    /* pack pixels 8-15 for R */
    px[0] = _mm_packus_epi16(px[4], px[5]);    /* pack pixels 0-15 for R */
    px[4] = _mm_cvtps_epi32(p[4]);    /* convert to int32 for G */
    px[5] = _mm_cvtps_epi32(p[5]);    /* convert to int32 for G */
    px[6] = _mm_cvtps_epi32(p[6]);    /* convert to int32 for G */
    px[7] = _mm_cvtps_epi32(p[7]);    /* convert to int32 for G */
    px[4] = _mm_packus_epi32(px[4], px[5]);    /* pack pixels 0-7 for G */
    px[5] = _mm_packus_epi32(px[6], px[7]);    /* pack pixels 8-15 for G */
    px[1] = _mm_packus_epi16(px[4], px[5]);    /* pack pixels 0-15 for G */
    px[4] = _mm_cvtps_epi32(p[8]);    /* convert to int32 for B */
    px[5] = _mm_cvtps_epi32(p[9]);    /* convert to int32 for B */
    px[6] = _mm_cvtps_epi32(p[10]);    /* convert to int32 for B */
    px[7] = _mm_cvtps_epi32(p[11]);    /* convert to int32 for B */
    px[4] = _mm_packus_epi32(px[4], px[5]);    /* pack pixels 0-7 for B */
    px[5] = _mm_packus_epi32(px[6], px[7]);    /* pack pixels 8-15 for B */
    px[2] = _mm_packus_epi16(px[4], px[5]);    /* pack pixels 0-15 for B */
    _mm_storeu_si128((__m128i *)dstPtrR, px[0]);    /* store [R01|R02|R03|R04|R05|R06|R07|R08|R09|R10|R11|R12|R13|R14|R15|R16] */
    _mm_storeu_si128((__m128i *)dstPtrG, px[1]);    /* store [G01|G02|G03|G04|G05|G06|G07|G08|G09|G10|G11|G12|G13|G14|G15|G16] */
    _mm_storeu_si128((__m128i *)dstPtrB, px[2]);    /* store [B01|B02|B03|B04|B05|B06|B07|B08|B09|B10|B11|B12|B13|B14|B15|B16] */

    return RPP_SUCCESS;
}

inline RppStatus rpp_load48_u8pln3_to_f32pln3(Rpp8u *srcPtrR, Rpp8u *srcPtrG, Rpp8u *srcPtrB, __m128 *p)
{
    __m128i px[3];
    __m128i mask0 = _mm_setr_epi8(0, 0x80, 0x80, 0x80, 1, 0x80, 0x80, 0x80, 2, 0x80, 0x80, 0x80, 3, 0x80, 0x80, 0x80);
    __m128i mask1 = _mm_setr_epi8(4, 0x80, 0x80, 0x80, 5, 0x80, 0x80, 0x80, 6, 0x80, 0x80, 0x80, 7, 0x80, 0x80, 0x80);
    __m128i mask2 = _mm_setr_epi8(8, 0x80, 0x80, 0x80, 9, 0x80, 0x80, 0x80, 10, 0x80, 0x80, 0x80, 11, 0x80, 0x80, 0x80);
    __m128i mask3 = _mm_setr_epi8(12, 0x80, 0x80, 0x80, 13, 0x80, 0x80, 0x80, 14, 0x80, 0x80, 0x80, 15, 0x80, 0x80, 0x80);
    px[0] = _mm_loadu_si128((__m128i *)srcPtrR);    /* load [R01|R02|R03|R04|R05|R06|R07|R08|R09|R10|R11|R12|R13|R14|R15|R16] */
    px[1] = _mm_loadu_si128((__m128i *)srcPtrG);    /* load [G01|G02|G03|G04|G05|G06|G07|G08|G09|G10|G11|G12|G13|G14|G15|G16] */
    px[2] = _mm_loadu_si128((__m128i *)srcPtrB);    /* load [B01|B02|B03|B04|B05|B06|B07|B08|B09|B10|B11|B12|B13|B14|B15|B16] */
    p[0] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[0], mask0));    /* Contains R01-04 */
    p[1] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[0], mask1));    /* Contains R05-08 */
    p[2] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[0], mask2));    /* Contains R09-12 */
    p[3] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[0], mask3));    /* Contains R13-16 */
    p[4] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[1], mask0));    /* Contains G01-04 */
    p[5] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[1], mask1));    /* Contains G05-08 */
    p[6] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[1], mask2));    /* Contains G09-12 */
    p[7] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[1], mask3));    /* Contains G13-16 */
    p[8] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[2], mask0));    /* Contains B01-04 */
    p[9] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[2], mask1));    /* Contains B05-08 */
    p[10] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[2], mask2));    /* Contains B09-12 */
    p[11] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[2], mask3));    /* Contains B13-16 */

    return RPP_SUCCESS;
}

inline RppStatus rpp_store48_f32pln3_to_u8pkd3(Rpp8u *dstPtr, __m128 *p)
{
    __m128i px[7];
    __m128i pxMask = _mm_setr_epi8(0, 4, 8, 1, 5, 9, 2, 6, 10, 3, 7, 11, 12, 13, 14, 15);
    __m128i pxZero = _mm_setzero_si128();

    px[4] = _mm_cvtps_epi32(p[0]);    /* convert to int32 for R01-04 */
    px[5] = _mm_cvtps_epi32(p[4]);    /* convert to int32 for G01-04 */
    px[6] = _mm_cvtps_epi32(p[8]);    /* convert to int32 for B01-04 */
    px[4] = _mm_packus_epi32(px[4], px[5]);    /* pack pixels 0-7 as R01-04|G01-04 */
    px[5] = _mm_packus_epi32(px[6], pxZero);    /* pack pixels 8-15 as B01-04|X01-04 */
    px[0] = _mm_packus_epi16(px[4], px[5]);    /* pack pixels 0-15 as [R01|R02|R03|R04|G01|G02|G03|G04|B01|B02|B03|B04|00|00|00|00] */
    px[4] = _mm_cvtps_epi32(p[1]);    /* convert to int32 for R05-08 */
    px[5] = _mm_cvtps_epi32(p[5]);    /* convert to int32 for G05-08 */
    px[6] = _mm_cvtps_epi32(p[9]);    /* convert to int32 for B05-08 */
    px[4] = _mm_packus_epi32(px[4], px[5]);    /* pack pixels 0-7 as R05-08|G05-08 */
    px[5] = _mm_packus_epi32(px[6], pxZero);    /* pack pixels 8-15 as B05-08|X01-04 */
    px[1] = _mm_packus_epi16(px[4], px[5]);    /* pack pixels 0-15 as [R05|R06|R07|R08|G05|G06|G07|G08|B05|B06|B07|B08|00|00|00|00] */
    px[4] = _mm_cvtps_epi32(p[2]);    /* convert to int32 for R09-12 */
    px[5] = _mm_cvtps_epi32(p[6]);    /* convert to int32 for G09-12 */
    px[6] = _mm_cvtps_epi32(p[10]);    /* convert to int32 for B09-12 */
    px[4] = _mm_packus_epi32(px[4], px[5]);    /* pack pixels 0-7 as R09-12|G09-12 */
    px[5] = _mm_packus_epi32(px[6], pxZero);    /* pack pixels 8-15 as B09-12|X01-04 */
    px[2] = _mm_packus_epi16(px[4], px[5]);    /* pack pixels 0-15 as [R09|R10|R11|R12|G09|G10|G11|G12|B09|B10|B11|B12|00|00|00|00] */
    px[4] = _mm_cvtps_epi32(p[3]);    /* convert to int32 for R13-16 */
    px[5] = _mm_cvtps_epi32(p[7]);    /* convert to int32 for G13-16 */
    px[6] = _mm_cvtps_epi32(p[11]);    /* convert to int32 for B13-16 */
    px[4] = _mm_packus_epi32(px[4], px[5]);    /* pack pixels 0-7 as R13-16|G13-16 */
    px[5] = _mm_packus_epi32(px[6], pxZero);    /* pack pixels 8-15 as B13-16|X01-04 */
    px[3] = _mm_packus_epi16(px[4], px[5]);    /* pack pixels 0-15 as [R13|R14|R15|R16|G13|G14|G15|G16|B13|B14|B15|B16|00|00|00|00] */
    px[0] = _mm_shuffle_epi8(px[0], pxMask);    /* shuffle to get [R01|G01|B01|R02|G02|B02|R03|G03|B03|R04|G04|B04|00|00|00|00] */
    px[1] = _mm_shuffle_epi8(px[1], pxMask);    /* shuffle to get [R05|G05|B05|R06|G06|B06|R07|G07|B07|R08|G08|B08|00|00|00|00] */
    px[2] = _mm_shuffle_epi8(px[2], pxMask);    /* shuffle to get [R09|G09|B09|R10|G10|B10|R11|G11|B11|R12|G12|B12|00|00|00|00] */
    px[3] = _mm_shuffle_epi8(px[3], pxMask);    /* shuffle to get [R13|G13|B13|R14|G14|B14|R15|G15|B15|R16|G16|B16|00|00|00|00] */
    _mm_storeu_si128((__m128i *)dstPtr, px[0]);           /* store [R01|G01|B01|R02|G02|B02|R03|G03|B03|R04|G04|B04|00|00|00|00] */
    _mm_storeu_si128((__m128i *)(dstPtr + 12), px[1]);    /* store [R05|G05|B05|R06|G06|B06|R07|G07|B07|R08|G08|B08|00|00|00|00] */
    _mm_storeu_si128((__m128i *)(dstPtr + 24), px[2]);    /* store [R09|G09|B09|R10|G10|B10|R11|G11|B11|R12|G12|B12|00|00|00|00] */
    _mm_storeu_si128((__m128i *)(dstPtr + 36), px[3]);    /* store [R13|G13|B13|R14|G14|B14|R15|G15|B15|R16|G16|B16|00|00|00|00] */

    return RPP_SUCCESS;
}

inline RppStatus rpp_load48_u8pkd3_to_u8pln3(Rpp8u *srcPtr, __m128i *px)
{
    __m128i pxSrc[8];
    __m128i pxMask = _mm_setr_epi8(0, 3, 6, 9, 1, 4, 7, 10, 2, 5, 8, 11, 12, 13, 14, 15);
    __m128i pxMaskRGB = _mm_setr_epi8(0, 4, 8, 12, 2, 6, 10, 14, 1, 5, 9, 13, 3, 7, 11, 15);

    pxSrc[0] = _mm_loadu_si128((__m128i *)srcPtr);           /* load [R01|G01|B01|R02|G02|B02|R03|G03|B03|R04|G04|B04|R05|G05|B05|R06] - Need RGB 01-04 */
    pxSrc[1] = _mm_loadu_si128((__m128i *)(srcPtr + 12));    /* load [R05|G05|B05|R06|G06|B06|R07|G07|B07|R08|G08|B08|R09|G09|B09|R10] - Need RGB 05-08 */
    pxSrc[2] = _mm_loadu_si128((__m128i *)(srcPtr + 24));    /* load [R09|G09|B09|R10|G10|B10|R11|G11|B11|R12|G12|B12|R13|G13|B13|R14] - Need RGB 09-12 */
    pxSrc[3] = _mm_loadu_si128((__m128i *)(srcPtr + 36));    /* load [R13|G13|B13|R14|G14|B14|R15|G15|B15|R16|G16|B16|R17|G17|B17|R18] - Need RGB 13-16 */
    pxSrc[0] = _mm_shuffle_epi8(pxSrc[0], pxMask);    /* shuffle to get [R01|R02|R03|R04|G01|G02|G03|G04 || B01|B02|B03|B04|R05|G05|B05|R06] - Need R01-04, G01-04, B01-04 */
    pxSrc[1] = _mm_shuffle_epi8(pxSrc[1], pxMask);    /* shuffle to get [R05|R06|R07|R08|G05|G06|G07|G08 || B05|B06|B07|B08|R09|G09|B09|R10] - Need R05-08, G05-08, B05-08 */
    pxSrc[2] = _mm_shuffle_epi8(pxSrc[2], pxMask);    /* shuffle to get [R09|R10|R11|R12|G09|G10|G11|G12 || B09|B10|B11|B12|R13|G13|B13|R14] - Need R09-12, G09-12, B09-12 */
    pxSrc[3] = _mm_shuffle_epi8(pxSrc[3], pxMask);    /* shuffle to get [R13|R14|R15|R16|G13|G14|G15|G16 || B13|B14|B15|B16|R17|G17|B17|R18] - Need R13-16, G13-16, B13-16 */
    pxSrc[4] = _mm_unpacklo_epi8(pxSrc[0], pxSrc[1]);    /* unpack 8 lo-pixels of pxSrc[0] and pxSrc[1] */
    pxSrc[5] = _mm_unpacklo_epi8(pxSrc[2], pxSrc[3]);    /* unpack 8 lo-pixels of pxSrc[2] and pxSrc[3] */
    pxSrc[6] = _mm_unpackhi_epi8(pxSrc[0], pxSrc[1]);    /* unpack 8 hi-pixels of pxSrc[0] and pxSrc[1] */
    pxSrc[7] = _mm_unpackhi_epi8(pxSrc[2], pxSrc[3]);    /* unpack 8 hi-pixels of pxSrc[2] and pxSrc[3] */
    px[0] = _mm_shuffle_epi8(_mm_unpacklo_epi8(pxSrc[4], pxSrc[5]), pxMaskRGB);    /* unpack 8 lo-pixels of pxSrc[4] and pxSrc[5] to get R01-16 */
    px[1] = _mm_shuffle_epi8(_mm_unpackhi_epi8(pxSrc[4], pxSrc[5]), pxMaskRGB);    /* unpack 8 hi-pixels of pxSrc[4] and pxSrc[5] to get G01-16 */
    px[2] = _mm_shuffle_epi8(_mm_unpacklo_epi8(pxSrc[6], pxSrc[7]), pxMaskRGB);    /* unpack 8 lo-pixels of pxSrc[6] and pxSrc[7] to get B01-16 */

    return RPP_SUCCESS;
}

inline RppStatus rpp_store48_u8pln3_to_u8pln3(Rpp8u *dstPtrR, Rpp8u *dstPtrG, Rpp8u *dstPtrB, __m128i *px)
{
    _mm_storeu_si128((__m128i *)dstPtrR, px[0]);    /* store [R01|R02|R03|R04|R05|R06|R07|R08|R09|R10|R11|R12|R13|R14|R15|R16] */
    _mm_storeu_si128((__m128i *)dstPtrG, px[1]);    /* store [G01|G02|G03|G04|G05|G06|G07|G08|G09|G10|G11|G12|G13|G14|G15|G16] */
    _mm_storeu_si128((__m128i *)dstPtrB, px[2]);    /* store [B01|B02|B03|B04|B05|B06|B07|B08|B09|B10|B11|B12|B13|B14|B15|B16] */

    return RPP_SUCCESS;
}

inline RppStatus rpp_load48_u8pln3_to_u8pln3(Rpp8u *srcPtrR, Rpp8u *srcPtrG, Rpp8u *srcPtrB, __m128i *px)
{
    px[0] = _mm_loadu_si128((__m128i *)srcPtrR);    /* load [R01|R02|R03|R04|R05|R06|R07|R08|R09|R10|R11|R12|R13|R14|R15|R16] */
    px[1] = _mm_loadu_si128((__m128i *)srcPtrG);    /* load [G01|G02|G03|G04|G05|G06|G07|G08|G09|G10|G11|G12|G13|G14|G15|G16] */
    px[2] = _mm_loadu_si128((__m128i *)srcPtrB);    /* load [B01|B02|B03|B04|B05|B06|B07|B08|B09|B10|B11|B12|B13|B14|B15|B16] */

    return RPP_SUCCESS;
}

inline RppStatus rpp_store48_u8pln3_to_u8pkd3(Rpp8u *dstPtr, __m128i *px)
{
    __m128i pxDst[4];
    __m128i pxZero = _mm_setzero_si128();
    __m128i pxMaskRGBAtoRGB = _mm_setr_epi8(0, 1, 2, 4, 5, 6, 8, 9, 10, 12, 13, 14, 3, 7, 11, 15);
    pxDst[0] = _mm_unpacklo_epi8(px[1], pxZero);
    pxDst[1] = _mm_unpackhi_epi8(px[1], pxZero);
    pxDst[2] = _mm_unpacklo_epi8(px[0], px[2]);
    pxDst[3] = _mm_unpackhi_epi8(px[0], px[2]);
    _mm_storeu_si128((__m128i *)dstPtr, _mm_shuffle_epi8(_mm_unpacklo_epi8(pxDst[2], pxDst[0]), pxMaskRGBAtoRGB));           /* store [R01|G01|B01|R02|G02|B02|R03|G03|B03|R04|G04|B04|00|00|00|00] */
    _mm_storeu_si128((__m128i *)(dstPtr + 12), _mm_shuffle_epi8(_mm_unpackhi_epi8(pxDst[2], pxDst[0]), pxMaskRGBAtoRGB));    /* store [R05|G05|B05|R06|G06|B06|R07|G07|B07|R08|G08|B08|00|00|00|00] */
    _mm_storeu_si128((__m128i *)(dstPtr + 24), _mm_shuffle_epi8(_mm_unpacklo_epi8(pxDst[3], pxDst[1]), pxMaskRGBAtoRGB));    /* store [R09|G09|B09|R10|G10|B10|R11|G11|B11|R12|G12|B12|00|00|00|00] */
    _mm_storeu_si128((__m128i *)(dstPtr + 36), _mm_shuffle_epi8(_mm_unpackhi_epi8(pxDst[3], pxDst[1]), pxMaskRGBAtoRGB));    /* store [R13|G13|B13|R14|G14|B14|R15|G15|B15|R16|G16|B16|00|00|00|00] */

    return RPP_SUCCESS;
}

inline RppStatus rpp_load16_u8_to_f32(Rpp8u *srcPtr, __m128 *p)
{
    __m128i px[2];
    __m128i pxZero = _mm_setzero_si128();

    px[0] =  _mm_loadu_si128((__m128i *)srcPtr);    /* load pixels 0-15 */
    px[1] = _mm_unpackhi_epi8(px[0], pxZero);    /* pixels 8-15 */
    px[0] = _mm_unpacklo_epi8(px[0], pxZero);    /* pixels 0-7 */
    p[0] = _mm_cvtepi32_ps(_mm_unpacklo_epi16(px[0], pxZero));    /* pixels 0-3 */
    p[1] = _mm_cvtepi32_ps(_mm_unpackhi_epi16(px[0], pxZero));    /* pixels 4-7 */
    p[2] = _mm_cvtepi32_ps(_mm_unpacklo_epi16(px[1], pxZero));    /* pixels 8-11 */
    p[3] = _mm_cvtepi32_ps(_mm_unpackhi_epi16(px[1], pxZero));    /* pixels 12-15 */

    return RPP_SUCCESS;
}

inline RppStatus rpp_store16_f32_to_u8(Rpp8u *dstPtr, __m128 *p)
{
    __m128i px[4];

    px[0] = _mm_cvtps_epi32(p[0]);    /* pixels 0-3 */
    px[1] = _mm_cvtps_epi32(p[1]);    /* pixels 4-7 */
    px[2] = _mm_cvtps_epi32(p[2]);    /* pixels 8-11 */
    px[3] = _mm_cvtps_epi32(p[3]);    /* pixels 12-15 */
    px[0] = _mm_packus_epi32(px[0], px[1]);    /* pixels 0-7 */
    px[1] = _mm_packus_epi32(px[2], px[3]);    /* pixels 8-15 */
    px[0] = _mm_packus_epi16(px[0], px[1]);    /* pixels 0-15 */
    _mm_storeu_si128((__m128i *)dstPtr, px[0]);    /* store pixels 0-15 */

    return RPP_SUCCESS;
}

inline RppStatus rpp_load16_f32_to_f32(Rpp32f *srcPtr, __m128 *p)
{
    p[0] = _mm_loadu_ps(srcPtr);
    p[1] = _mm_loadu_ps(&srcPtr[4]);
    p[2] = _mm_loadu_ps(&srcPtr[8]);
    p[3] = _mm_loadu_ps(&srcPtr[12]);

    return RPP_SUCCESS;
}

inline RppStatus rpp_load12_f32pkd3_to_f32pln3(Rpp32f *srcPtr, __m128 *p)
{
    p[0] = _mm_loadu_ps(srcPtr);
    p[1] = _mm_loadu_ps(&srcPtr[3]);
    p[2] = _mm_loadu_ps(&srcPtr[6]);
    p[3] = _mm_loadu_ps(&srcPtr[9]);
    _MM_TRANSPOSE4_PS(p[0], p[1], p[2], p[3]);

    return RPP_SUCCESS;
}

inline RppStatus rpp_store12_f32pln3_to_f32pln3(Rpp32f *dstPtrR, Rpp32f *dstPtrG, Rpp32f *dstPtrB, __m128 *p)
{
    _mm_storeu_ps(dstPtrR, p[0]);
    _mm_storeu_ps(dstPtrG, p[1]);
    _mm_storeu_ps(dstPtrB, p[2]);

    return RPP_SUCCESS;
}

inline RppStatus rpp_load12_f32pln3_to_f32pln3(Rpp32f *srcPtrR, Rpp32f *srcPtrG, Rpp32f *srcPtrB, __m128 *p)
{
    p[0] = _mm_loadu_ps(srcPtrR);
    p[1] = _mm_loadu_ps(srcPtrG);
    p[2] = _mm_loadu_ps(srcPtrB);

    return RPP_SUCCESS;
}

inline RppStatus rpp_store12_f32pln3_to_f32pkd3(Rpp32f *dstPtr, __m128 *p)
{
    _MM_TRANSPOSE4_PS(p[0], p[1], p[2], p[3]);
    _mm_storeu_ps(dstPtr, p[0]);
    _mm_storeu_ps(&dstPtr[3], p[1]);
    _mm_storeu_ps(&dstPtr[6], p[2]);
    _mm_storeu_ps(&dstPtr[9], p[3]);

    return RPP_SUCCESS;
}

inline RppStatus rpp_load4_f32_to_f32(Rpp32f *srcPtr, __m128 *p)
{
    p[0] = _mm_loadu_ps(srcPtr);

    return RPP_SUCCESS;
}

inline RppStatus rpp_store4_f32_to_f32(Rpp32f *dstPtr, __m128 *p)
{
    _mm_storeu_ps(dstPtr, p[0]);

    return RPP_SUCCESS;
}

inline RppStatus rpp_load48_i8pkd3_to_f32pln3(Rpp8s *srcPtr, __m128 *p)
{
    __m128i px[4];
    __m128i pxConvertI8 = _mm_set1_epi8((char)128);
    __m128i maskR = _mm_setr_epi8(0, 0x80, 0x80, 0x80, 3, 0x80, 0x80, 0x80, 6, 0x80, 0x80, 0x80, 9, 0x80, 0x80, 0x80);
    __m128i maskG = _mm_setr_epi8(1, 0x80, 0x80, 0x80, 4, 0x80, 0x80, 0x80, 7, 0x80, 0x80, 0x80, 10, 0x80, 0x80, 0x80);
    __m128i maskB = _mm_setr_epi8(2, 0x80, 0x80, 0x80, 5, 0x80, 0x80, 0x80, 8, 0x80, 0x80, 0x80, 11, 0x80, 0x80, 0x80);
    px[0] = _mm_add_epi8(pxConvertI8, _mm_loadu_si128((__m128i *)srcPtr));           /* add I8 conversion param to load [R01|G01|B01|R02|G02|B02|R03|G03|B03|R04|G04|B04|R05|G05|B05|R06] - Need RGB 01-04 */
    px[1] = _mm_add_epi8(pxConvertI8, _mm_loadu_si128((__m128i *)(srcPtr + 12)));    /* add I8 conversion param to load [R05|G05|B05|R06|G06|B06|R07|G07|B07|R08|G08|B08|R09|G09|B09|R10] - Need RGB 05-08 */
    px[2] = _mm_add_epi8(pxConvertI8, _mm_loadu_si128((__m128i *)(srcPtr + 24)));    /* add I8 conversion param to load [R09|G09|B09|R10|G10|B10|R11|G11|B11|R12|G12|B12|R13|G13|B13|R14] - Need RGB 09-12 */
    px[3] = _mm_add_epi8(pxConvertI8, _mm_loadu_si128((__m128i *)(srcPtr + 36)));    /* add I8 conversion param to load [R13|G13|B13|R14|G14|B14|R15|G15|B15|R16|G16|B16|R17|G17|B17|R18] - Need RGB 13-16 */
    p[0] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[0], maskR));    /* Contains R01-04 */
    p[1] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[1], maskR));    /* Contains R05-08 */
    p[2] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[2], maskR));    /* Contains R09-12 */
    p[3] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[3], maskR));    /* Contains R13-16 */
    p[4] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[0], maskG));    /* Contains G01-04 */
    p[5] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[1], maskG));    /* Contains G05-08 */
    p[6] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[2], maskG));    /* Contains G09-12 */
    p[7] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[3], maskG));    /* Contains G13-16 */
    p[8] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[0], maskB));    /* Contains B01-04 */
    p[9] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[1], maskB));    /* Contains B05-08 */
    p[10] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[2], maskB));    /* Contains B09-12 */
    p[11] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[3], maskB));    /* Contains B13-16 */

    return RPP_SUCCESS;
}

inline RppStatus rpp_store48_f32pln3_to_i8pln3(Rpp8s *dstPtrR, Rpp8s *dstPtrG, Rpp8s *dstPtrB, __m128 *p)
{
    __m128i px[8];
    __m128i pxConvertI8 = _mm_set1_epi8((char)128);

    px[4] = _mm_cvtps_epi32(p[0]);    /* convert to int32 for R */
    px[5] = _mm_cvtps_epi32(p[1]);    /* convert to int32 for R */
    px[6] = _mm_cvtps_epi32(p[2]);    /* convert to int32 for R */
    px[7] = _mm_cvtps_epi32(p[3]);    /* convert to int32 for R */
    px[4] = _mm_packus_epi32(px[4], px[5]);    /* pack pixels 0-7 for R */
    px[5] = _mm_packus_epi32(px[6], px[7]);    /* pack pixels 8-15 for R */
    px[0] = _mm_packus_epi16(px[4], px[5]);    /* pack pixels 0-15 for R */
    px[4] = _mm_cvtps_epi32(p[4]);    /* convert to int32 for G */
    px[5] = _mm_cvtps_epi32(p[5]);    /* convert to int32 for G */
    px[6] = _mm_cvtps_epi32(p[6]);    /* convert to int32 for G */
    px[7] = _mm_cvtps_epi32(p[7]);    /* convert to int32 for G */
    px[4] = _mm_packus_epi32(px[4], px[5]);    /* pack pixels 0-7 for G */
    px[5] = _mm_packus_epi32(px[6], px[7]);    /* pack pixels 8-15 for G */
    px[1] = _mm_packus_epi16(px[4], px[5]);    /* pack pixels 0-15 for G */
    px[4] = _mm_cvtps_epi32(p[8]);    /* convert to int32 for B */
    px[5] = _mm_cvtps_epi32(p[9]);    /* convert to int32 for B */
    px[6] = _mm_cvtps_epi32(p[10]);    /* convert to int32 for B */
    px[7] = _mm_cvtps_epi32(p[11]);    /* convert to int32 for B */
    px[4] = _mm_packus_epi32(px[4], px[5]);    /* pack pixels 0-7 for B */
    px[5] = _mm_packus_epi32(px[6], px[7]);    /* pack pixels 8-15 for B */
    px[2] = _mm_packus_epi16(px[4], px[5]);    /* pack pixels 0-15 for B */
    px[0] = _mm_sub_epi8(px[0], pxConvertI8);    /* convert back to i8 for px0 store */
    px[1] = _mm_sub_epi8(px[1], pxConvertI8);    /* convert back to i8 for px1 store */
    px[2] = _mm_sub_epi8(px[2], pxConvertI8);    /* convert back to i8 for px2 store */
    _mm_storeu_si128((__m128i *)dstPtrR, px[0]);    /* store [R01|R02|R03|R04|R05|R06|R07|R08|R09|R10|R11|R12|R13|R14|R15|R16] */
    _mm_storeu_si128((__m128i *)dstPtrG, px[1]);    /* store [G01|G02|G03|G04|G05|G06|G07|G08|G09|G10|G11|G12|G13|G14|G15|G16] */
    _mm_storeu_si128((__m128i *)dstPtrB, px[2]);    /* store [B01|B02|B03|B04|B05|B06|B07|B08|B09|B10|B11|B12|B13|B14|B15|B16] */

    return RPP_SUCCESS;
}

inline RppStatus rpp_load48_i8pln3_to_f32pln3(Rpp8s *srcPtrR, Rpp8s *srcPtrG, Rpp8s *srcPtrB, __m128 *p)
{
    __m128i px[3];
    __m128i pxConvertI8 = _mm_set1_epi8((char)128);
    __m128i mask0 = _mm_setr_epi8(0, 0x80, 0x80, 0x80, 1, 0x80, 0x80, 0x80, 2, 0x80, 0x80, 0x80, 3, 0x80, 0x80, 0x80);
    __m128i mask1 = _mm_setr_epi8(4, 0x80, 0x80, 0x80, 5, 0x80, 0x80, 0x80, 6, 0x80, 0x80, 0x80, 7, 0x80, 0x80, 0x80);
    __m128i mask2 = _mm_setr_epi8(8, 0x80, 0x80, 0x80, 9, 0x80, 0x80, 0x80, 10, 0x80, 0x80, 0x80, 11, 0x80, 0x80, 0x80);
    __m128i mask3 = _mm_setr_epi8(12, 0x80, 0x80, 0x80, 13, 0x80, 0x80, 0x80, 14, 0x80, 0x80, 0x80, 15, 0x80, 0x80, 0x80);
    px[0] = _mm_add_epi8(pxConvertI8, _mm_loadu_si128((__m128i *)srcPtrR));    /* add I8 conversion param to load [R01|R02|R03|R04|R05|R06|R07|R08|R09|R10|R11|R12|R13|R14|R15|R16] */
    px[1] = _mm_add_epi8(pxConvertI8, _mm_loadu_si128((__m128i *)srcPtrG));    /* add I8 conversion param to load [G01|G02|G03|G04|G05|G06|G07|G08|G09|G10|G11|G12|G13|G14|G15|G16] */
    px[2] = _mm_add_epi8(pxConvertI8, _mm_loadu_si128((__m128i *)srcPtrB));    /* add I8 conversion param to load [B01|B02|B03|B04|B05|B06|B07|B08|B09|B10|B11|B12|B13|B14|B15|B16] */
    p[0] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[0], mask0));    /* Contains R01-04 */
    p[1] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[0], mask1));    /* Contains R05-08 */
    p[2] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[0], mask2));    /* Contains R09-12 */
    p[3] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[0], mask3));    /* Contains R13-16 */
    p[4] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[1], mask0));    /* Contains G01-04 */
    p[5] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[1], mask1));    /* Contains G05-08 */
    p[6] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[1], mask2));    /* Contains G09-12 */
    p[7] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[1], mask3));    /* Contains G13-16 */
    p[8] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[2], mask0));    /* Contains B01-04 */
    p[9] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[2], mask1));    /* Contains B05-08 */
    p[10] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[2], mask2));    /* Contains B09-12 */
    p[11] = _mm_cvtepi32_ps(_mm_shuffle_epi8(px[2], mask3));    /* Contains B13-16 */

    return RPP_SUCCESS;
}

inline RppStatus rpp_store48_f32pln3_to_i8pkd3(Rpp8s *dstPtr, __m128 *p)
{
    __m128i px[7];
    __m128i pxMask = _mm_setr_epi8(0, 4, 8, 1, 5, 9, 2, 6, 10, 3, 7, 11, 12, 13, 14, 15);
    __m128i pxConvertI8 = _mm_set1_epi8((char)128);
    __m128i pxZero = _mm_setzero_si128();

    px[4] = _mm_cvtps_epi32(p[0]);    /* convert to int32 for R01-04 */
    px[5] = _mm_cvtps_epi32(p[4]);    /* convert to int32 for G01-04 */
    px[6] = _mm_cvtps_epi32(p[8]);    /* convert to int32 for B01-04 */
    px[4] = _mm_packus_epi32(px[4], px[5]);    /* pack pixels 0-7 as R01-04|G01-04 */
    px[5] = _mm_packus_epi32(px[6], pxZero);    /* pack pixels 8-15 as B01-04|X01-04 */
    px[0] = _mm_packus_epi16(px[4], px[5]);    /* pack pixels 0-15 as [R01|R02|R03|R04|G01|G02|G03|G04|B01|B02|B03|B04|00|00|00|00] */
    px[4] = _mm_cvtps_epi32(p[1]);    /* convert to int32 for R05-08 */
    px[5] = _mm_cvtps_epi32(p[5]);    /* convert to int32 for G05-08 */
    px[6] = _mm_cvtps_epi32(p[9]);    /* convert to int32 for B05-08 */
    px[4] = _mm_packus_epi32(px[4], px[5]);    /* pack pixels 0-7 as R05-08|G05-08 */
    px[5] = _mm_packus_epi32(px[6], pxZero);    /* pack pixels 8-15 as B05-08|X01-04 */
    px[1] = _mm_packus_epi16(px[4], px[5]);    /* pack pixels 0-15 as [R05|R06|R07|R08|G05|G06|G07|G08|B05|B06|B07|B08|00|00|00|00] */
    px[4] = _mm_cvtps_epi32(p[2]);    /* convert to int32 for R09-12 */
    px[5] = _mm_cvtps_epi32(p[6]);    /* convert to int32 for G09-12 */
    px[6] = _mm_cvtps_epi32(p[10]);    /* convert to int32 for B09-12 */
    px[4] = _mm_packus_epi32(px[4], px[5]);    /* pack pixels 0-7 as R09-12|G09-12 */
    px[5] = _mm_packus_epi32(px[6], pxZero);    /* pack pixels 8-15 as B09-12|X01-04 */
    px[2] = _mm_packus_epi16(px[4], px[5]);    /* pack pixels 0-15 as [R09|R10|R11|R12|G09|G10|G11|G12|B09|B10|B11|B12|00|00|00|00] */
    px[4] = _mm_cvtps_epi32(p[3]);    /* convert to int32 for R13-16 */
    px[5] = _mm_cvtps_epi32(p[7]);    /* convert to int32 for G13-16 */
    px[6] = _mm_cvtps_epi32(p[11]);    /* convert to int32 for B13-16 */
    px[4] = _mm_packus_epi32(px[4], px[5]);    /* pack pixels 0-7 as R13-16|G13-16 */
    px[5] = _mm_packus_epi32(px[6], pxZero);    /* pack pixels 8-15 as B13-16|X01-04 */
    px[3] = _mm_packus_epi16(px[4], px[5]);    /* pack pixels 0-15 as [R13|R14|R15|R16|G13|G14|G15|G16|B13|B14|B15|B16|00|00|00|00] */
    px[0] = _mm_sub_epi8(px[0], pxConvertI8);    /* convert back to i8 for px0 store */
    px[1] = _mm_sub_epi8(px[1], pxConvertI8);    /* convert back to i8 for px1 store */
    px[2] = _mm_sub_epi8(px[2], pxConvertI8);    /* convert back to i8 for px2 store */
    px[3] = _mm_sub_epi8(px[3], pxConvertI8);    /* convert back to i8 for px3 store */
    px[0] = _mm_shuffle_epi8(px[0], pxMask);    /* shuffle to get [R01|G01|B01|R02|G02|B02|R03|G03|B03|R04|G04|B04|00|00|00|00] */
    px[1] = _mm_shuffle_epi8(px[1], pxMask);    /* shuffle to get [R05|G05|B05|R06|G06|B06|R07|G07|B07|R08|G08|B08|00|00|00|00] */
    px[2] = _mm_shuffle_epi8(px[2], pxMask);    /* shuffle to get [R09|G09|B09|R10|G10|B10|R11|G11|B11|R12|G12|B12|00|00|00|00] */
    px[3] = _mm_shuffle_epi8(px[3], pxMask);    /* shuffle to get [R13|G13|B13|R14|G14|B14|R15|G15|B15|R16|G16|B16|00|00|00|00] */
    _mm_storeu_si128((__m128i *)dstPtr, px[0]);           /* store [R01|G01|B01|R02|G02|B02|R03|G03|B03|R04|G04|B04|00|00|00|00] */
    _mm_storeu_si128((__m128i *)(dstPtr + 12), px[1]);    /* store [R05|G05|B05|R06|G06|B06|R07|G07|B07|R08|G08|B08|00|00|00|00] */
    _mm_storeu_si128((__m128i *)(dstPtr + 24), px[2]);    /* store [R09|G09|B09|R10|G10|B10|R11|G11|B11|R12|G12|B12|00|00|00|00] */
    _mm_storeu_si128((__m128i *)(dstPtr + 36), px[3]);    /* store [R13|G13|B13|R14|G14|B14|R15|G15|B15|R16|G16|B16|00|00|00|00] */

    return RPP_SUCCESS;
}

inline RppStatus rpp_load48_i8pkd3_to_i8pln3(Rpp8s *srcPtr, __m128i *px)
{
    __m128i pxSrc[8];
    __m128i pxMask = _mm_setr_epi8(0, 3, 6, 9, 1, 4, 7, 10, 2, 5, 8, 11, 12, 13, 14, 15);
    __m128i pxMaskRGB = _mm_setr_epi8(0, 4, 8, 12, 2, 6, 10, 14, 1, 5, 9, 13, 3, 7, 11, 15);

    pxSrc[0] = _mm_loadu_si128((__m128i *)srcPtr);           /* load [R01|G01|B01|R02|G02|B02|R03|G03|B03|R04|G04|B04|R05|G05|B05|R06] - Need RGB 01-04 */
    pxSrc[1] = _mm_loadu_si128((__m128i *)(srcPtr + 12));    /* load [R05|G05|B05|R06|G06|B06|R07|G07|B07|R08|G08|B08|R09|G09|B09|R10] - Need RGB 05-08 */
    pxSrc[2] = _mm_loadu_si128((__m128i *)(srcPtr + 24));    /* load [R09|G09|B09|R10|G10|B10|R11|G11|B11|R12|G12|B12|R13|G13|B13|R14] - Need RGB 09-12 */
    pxSrc[3] = _mm_loadu_si128((__m128i *)(srcPtr + 36));    /* load [R13|G13|B13|R14|G14|B14|R15|G15|B15|R16|G16|B16|R17|G17|B17|R18] - Need RGB 13-16 */
    pxSrc[0] = _mm_shuffle_epi8(pxSrc[0], pxMask);    /* shuffle to get [R01|R02|R03|R04|G01|G02|G03|G04 || B01|B02|B03|B04|R05|G05|B05|R06] - Need R01-04, G01-04, B01-04 */
    pxSrc[1] = _mm_shuffle_epi8(pxSrc[1], pxMask);    /* shuffle to get [R05|R06|R07|R08|G05|G06|G07|G08 || B05|B06|B07|B08|R09|G09|B09|R10] - Need R05-08, G05-08, B05-08 */
    pxSrc[2] = _mm_shuffle_epi8(pxSrc[2], pxMask);    /* shuffle to get [R09|R10|R11|R12|G09|G10|G11|G12 || B09|B10|B11|B12|R13|G13|B13|R14] - Need R09-12, G09-12, B09-12 */
    pxSrc[3] = _mm_shuffle_epi8(pxSrc[3], pxMask);    /* shuffle to get [R13|R14|R15|R16|G13|G14|G15|G16 || B13|B14|B15|B16|R17|G17|B17|R18] - Need R13-16, G13-16, B13-16 */
    pxSrc[4] = _mm_unpacklo_epi8(pxSrc[0], pxSrc[1]);    /* unpack 8 lo-pixels of pxSrc[0] and pxSrc[1] */
    pxSrc[5] = _mm_unpacklo_epi8(pxSrc[2], pxSrc[3]);    /* unpack 8 lo-pixels of pxSrc[2] and pxSrc[3] */
    pxSrc[6] = _mm_unpackhi_epi8(pxSrc[0], pxSrc[1]);    /* unpack 8 hi-pixels of pxSrc[0] and pxSrc[1] */
    pxSrc[7] = _mm_unpackhi_epi8(pxSrc[2], pxSrc[3]);    /* unpack 8 hi-pixels of pxSrc[2] and pxSrc[3] */
    px[0] = _mm_shuffle_epi8(_mm_unpacklo_epi8(pxSrc[4], pxSrc[5]), pxMaskRGB);    /* unpack 8 lo-pixels of pxSrc[4] and pxSrc[5] to get R01-16 */
    px[1] = _mm_shuffle_epi8(_mm_unpackhi_epi8(pxSrc[4], pxSrc[5]), pxMaskRGB);    /* unpack 8 hi-pixels of pxSrc[4] and pxSrc[5] to get G01-16 */
    px[2] = _mm_shuffle_epi8(_mm_unpacklo_epi8(pxSrc[6], pxSrc[7]), pxMaskRGB);    /* unpack 8 lo-pixels of pxSrc[6] and pxSrc[7] to get B01-16 */

    return RPP_SUCCESS;
}

inline RppStatus rpp_store48_i8pln3_to_i8pln3(Rpp8s *dstPtrR, Rpp8s *dstPtrG, Rpp8s *dstPtrB, __m128i *px)
{
    _mm_storeu_si128((__m128i *)dstPtrR, px[0]);    /* store [R01|R02|R03|R04|R05|R06|R07|R08|R09|R10|R11|R12|R13|R14|R15|R16] */
    _mm_storeu_si128((__m128i *)dstPtrG, px[1]);    /* store [G01|G02|G03|G04|G05|G06|G07|G08|G09|G10|G11|G12|G13|G14|G15|G16] */
    _mm_storeu_si128((__m128i *)dstPtrB, px[2]);    /* store [B01|B02|B03|B04|B05|B06|B07|B08|B09|B10|B11|B12|B13|B14|B15|B16] */

    return RPP_SUCCESS;
}

inline RppStatus rpp_load48_i8pln3_to_i8pln3(Rpp8s *srcPtrR, Rpp8s *srcPtrG, Rpp8s *srcPtrB, __m128i *px)
{
    px[0] = _mm_loadu_si128((__m128i *)srcPtrR);    /* load [R01|R02|R03|R04|R05|R06|R07|R08|R09|R10|R11|R12|R13|R14|R15|R16] */
    px[1] = _mm_loadu_si128((__m128i *)srcPtrG);    /* load [G01|G02|G03|G04|G05|G06|G07|G08|G09|G10|G11|G12|G13|G14|G15|G16] */
    px[2] = _mm_loadu_si128((__m128i *)srcPtrB);    /* load [B01|B02|B03|B04|B05|B06|B07|B08|B09|B10|B11|B12|B13|B14|B15|B16] */

    return RPP_SUCCESS;
}

inline RppStatus rpp_store48_i8pln3_to_i8pkd3(Rpp8s *dstPtr, __m128i *px)
{
    __m128i pxDst[4];
    __m128i pxZero = _mm_setzero_si128();
    __m128i pxMaskRGBAtoRGB = _mm_setr_epi8(0, 1, 2, 4, 5, 6, 8, 9, 10, 12, 13, 14, 3, 7, 11, 15);
    pxDst[0] = _mm_unpacklo_epi8(px[1], pxZero);    /* unpack 8 lo-pixels of px[1] and pxZero */
    pxDst[1] = _mm_unpackhi_epi8(px[1], pxZero);    /* unpack 8 hi-pixels of px[1] and pxZero */
    pxDst[2] = _mm_unpacklo_epi8(px[0], px[2]);    /* unpack 8 lo-pixels of px[0] and px[2] */
    pxDst[3] = _mm_unpackhi_epi8(px[0], px[2]);    /* unpack 8 hi-pixels of px[0] and px[2] */
    _mm_storeu_si128((__m128i *)dstPtr, _mm_shuffle_epi8(_mm_unpacklo_epi8(pxDst[2], pxDst[0]), pxMaskRGBAtoRGB));           /* store [R01|G01|B01|R02|G02|B02|R03|G03|B03|R04|G04|B04|00|00|00|00] */
    _mm_storeu_si128((__m128i *)(dstPtr + 12), _mm_shuffle_epi8(_mm_unpackhi_epi8(pxDst[2], pxDst[0]), pxMaskRGBAtoRGB));    /* store [R05|G05|B05|R06|G06|B06|R07|G07|B07|R08|G08|B08|00|00|00|00] */
    _mm_storeu_si128((__m128i *)(dstPtr + 24), _mm_shuffle_epi8(_mm_unpacklo_epi8(pxDst[3], pxDst[1]), pxMaskRGBAtoRGB));    /* store [R09|G09|B09|R10|G10|B10|R11|G11|B11|R12|G12|B12|00|00|00|00] */
    _mm_storeu_si128((__m128i *)(dstPtr + 36), _mm_shuffle_epi8(_mm_unpackhi_epi8(pxDst[3], pxDst[1]), pxMaskRGBAtoRGB));    /* store [R13|G13|B13|R14|G14|B14|R15|G15|B15|R16|G16|B16|00|00|00|00] */

    return RPP_SUCCESS;
}

inline RppStatus rpp_load16_i8_to_f32(Rpp8s *srcPtr, __m128 *p)
{
    __m128i px[2];
    __m128i pxZero = _mm_setzero_si128();
    __m128i pxConvertI8 = _mm_set1_epi8((char)128);

    px[0] =  _mm_loadu_si128((__m128i *)srcPtr);    /* load pixels 0-15 */
    px[0] = _mm_add_epi8(px[0], pxConvertI8);    /* convert to u8 for px0 compute */
    px[1] = _mm_unpackhi_epi8(px[0], pxZero);    /* pixels 8-15 */
    px[0] = _mm_unpacklo_epi8(px[0], pxZero);    /* pixels 0-7 */
    p[0] = _mm_cvtepi32_ps(_mm_unpacklo_epi16(px[0], pxZero));    /* pixels 0-3 */
    p[1] = _mm_cvtepi32_ps(_mm_unpackhi_epi16(px[0], pxZero));    /* pixels 4-7 */
    p[2] = _mm_cvtepi32_ps(_mm_unpacklo_epi16(px[1], pxZero));    /* pixels 8-11 */
    p[3] = _mm_cvtepi32_ps(_mm_unpackhi_epi16(px[1], pxZero));    /* pixels 12-15 */

    return RPP_SUCCESS;
}

inline RppStatus rpp_store16_f32_to_i8(Rpp8s *dstPtr, __m128 *p)
{
    __m128i px[4];
    __m128i pxConvertI8 = _mm_set1_epi8((char)128);

    px[0] = _mm_cvtps_epi32(p[0]);    /* pixels 0-3 */
    px[1] = _mm_cvtps_epi32(p[1]);    /* pixels 4-7 */
    px[2] = _mm_cvtps_epi32(p[2]);    /* pixels 8-11 */
    px[3] = _mm_cvtps_epi32(p[3]);    /* pixels 12-15 */
    px[0] = _mm_packus_epi32(px[0], px[1]);    /* pixels 0-7 */
    px[1] = _mm_packus_epi32(px[2], px[3]);    /* pixels 8-15 */
    px[0] = _mm_packus_epi16(px[0], px[1]);    /* pixels 0-15 */
    px[0] = _mm_sub_epi8(px[0], pxConvertI8);    /* convert back to i8 for px0 store */
    _mm_storeu_si128((__m128i *)dstPtr, px[0]);    /* store pixels 0-15 */

    return RPP_SUCCESS;
}

inline RppStatus rpp_normalize48(__m128 *p)
{
    p[0] = _mm_mul_ps(p[0], xmm_p1op255);
    p[1] = _mm_mul_ps(p[1], xmm_p1op255);
    p[2] = _mm_mul_ps(p[2], xmm_p1op255);
    p[3] = _mm_mul_ps(p[3], xmm_p1op255);
    p[4] = _mm_mul_ps(p[4], xmm_p1op255);
    p[5] = _mm_mul_ps(p[5], xmm_p1op255);
    p[6] = _mm_mul_ps(p[6], xmm_p1op255);
    p[7] = _mm_mul_ps(p[7], xmm_p1op255);
    p[8] = _mm_mul_ps(p[8], xmm_p1op255);
    p[9] = _mm_mul_ps(p[9], xmm_p1op255);
    p[10] = _mm_mul_ps(p[10], xmm_p1op255);
    p[11] = _mm_mul_ps(p[11], xmm_p1op255);

    return RPP_SUCCESS;
}

// AVX loads and stores

inline RppStatus rpp_load48_u8pkd3_to_f32pln3_avx(Rpp8u *srcPtr, __m256 *p)
{
    __m128i px[4];
    __m128i maskR = _mm_setr_epi8(0, 0x80, 0x80, 0x80, 3, 0x80, 0x80, 0x80, 6, 0x80, 0x80, 0x80, 9, 0x80, 0x80, 0x80);
    __m128i maskG = _mm_setr_epi8(1, 0x80, 0x80, 0x80, 4, 0x80, 0x80, 0x80, 7, 0x80, 0x80, 0x80, 10, 0x80, 0x80, 0x80);
    __m128i maskB = _mm_setr_epi8(2, 0x80, 0x80, 0x80, 5, 0x80, 0x80, 0x80, 8, 0x80, 0x80, 0x80, 11, 0x80, 0x80, 0x80);
    px[0] = _mm_loadu_si128((__m128i *)srcPtr);           /* load [R01|G01|B01|R02|G02|B02|R03|G03|B03|R04|G04|B04|R05|G05|B05|R06] - Need RGB 01-04 */
    px[1] = _mm_loadu_si128((__m128i *)(srcPtr + 12));    /* load [R05|G05|B05|R06|G06|B06|R07|G07|B07|R08|G08|B08|R09|G09|B09|R10] - Need RGB 05-08 */
    px[2] = _mm_loadu_si128((__m128i *)(srcPtr + 24));    /* load [R09|G09|B09|R10|G10|B10|R11|G11|B11|R12|G12|B12|R13|G13|B13|R14] - Need RGB 09-12 */
    px[3] = _mm_loadu_si128((__m128i *)(srcPtr + 36));    /* load [R13|G13|B13|R14|G14|B14|R15|G15|B15|R16|G16|B16|R17|G17|B17|R18] - Need RGB 13-16 */
    p[0] = _mm256_cvtepi32_ps(_mm256_setr_m128i(_mm_shuffle_epi8(px[0], maskR), _mm_shuffle_epi8(px[1], maskR)));    /* Contains R01-08 */
    p[1] = _mm256_cvtepi32_ps(_mm256_setr_m128i(_mm_shuffle_epi8(px[2], maskR), _mm_shuffle_epi8(px[3], maskR)));    /* Contains R09-16 */
    p[2] = _mm256_cvtepi32_ps(_mm256_setr_m128i(_mm_shuffle_epi8(px[0], maskG), _mm_shuffle_epi8(px[1], maskG)));    /* Contains G01-08 */
    p[3] = _mm256_cvtepi32_ps(_mm256_setr_m128i(_mm_shuffle_epi8(px[2], maskG), _mm_shuffle_epi8(px[3], maskG)));    /* Contains G09-16 */
    p[4] = _mm256_cvtepi32_ps(_mm256_setr_m128i(_mm_shuffle_epi8(px[0], maskB), _mm_shuffle_epi8(px[1], maskB)));    /* Contains B01-08 */
    p[5] = _mm256_cvtepi32_ps(_mm256_setr_m128i(_mm_shuffle_epi8(px[2], maskB), _mm_shuffle_epi8(px[3], maskB)));    /* Contains B09-16 */

    return RPP_SUCCESS;
}

inline RppStatus rpp_store48_f32pln3_to_u8pln3_avx(Rpp8u *dstPtrR, Rpp8u *dstPtrG, Rpp8u *dstPtrB, __m256 *p)
{
    __m256i pxCvt;
    __m128i px[4];

    pxCvt = _mm256_cvtps_epi32(p[0]);
    px[2] = _mm_packus_epi32(_mm256_extracti128_si256(pxCvt, 0), _mm256_extracti128_si256(pxCvt, 1));    /* pack pixels 0-7 for R */
    pxCvt = _mm256_cvtps_epi32(p[1]);
    px[3] = _mm_packus_epi32(_mm256_extracti128_si256(pxCvt, 0), _mm256_extracti128_si256(pxCvt, 1));    /* pack pixels 8-15 for R */
    px[0] = _mm_packus_epi16(px[2], px[3]);    /* pack pixels 0-15 for R */
    pxCvt = _mm256_cvtps_epi32(p[2]);
    px[2] = _mm_packus_epi32(_mm256_extracti128_si256(pxCvt, 0), _mm256_extracti128_si256(pxCvt, 1));    /* pack pixels 0-7 for G */
    pxCvt = _mm256_cvtps_epi32(p[3]);
    px[3] = _mm_packus_epi32(_mm256_extracti128_si256(pxCvt, 0), _mm256_extracti128_si256(pxCvt, 1));    /* pack pixels 8-15 for G */
    px[1] = _mm_packus_epi16(px[2], px[3]);    /* pack pixels 0-15 for G */
    pxCvt = _mm256_cvtps_epi32(p[4]);
    px[2] = _mm_packus_epi32(_mm256_extracti128_si256(pxCvt, 0), _mm256_extracti128_si256(pxCvt, 1));    /* pack pixels 0-7 for B */
    pxCvt = _mm256_cvtps_epi32(p[5]);
    px[3] = _mm_packus_epi32(_mm256_extracti128_si256(pxCvt, 0), _mm256_extracti128_si256(pxCvt, 1));    /* pack pixels 8-15 for B */
    px[2] = _mm_packus_epi16(px[2], px[3]);    /* pack pixels 0-15 for B */
    _mm_storeu_si128((__m128i *)dstPtrR, px[0]);    /* store [R01|R02|R03|R04|R05|R06|R07|R08|R09|R10|R11|R12|R13|R14|R15|R16] */
    _mm_storeu_si128((__m128i *)dstPtrG, px[1]);    /* store [G01|G02|G03|G04|G05|G06|G07|G08|G09|G10|G11|G12|G13|G14|G15|G16] */
    _mm_storeu_si128((__m128i *)dstPtrB, px[2]);    /* store [B01|B02|B03|B04|B05|B06|B07|B08|B09|B10|B11|B12|B13|B14|B15|B16] */

    return RPP_SUCCESS;
}

inline RppStatus rpp_load48_u8pln3_to_f32pln3_avx(Rpp8u *srcPtrR, Rpp8u *srcPtrG, Rpp8u *srcPtrB, __m256 *p)
{
    __m128i px[3];
    __m128i mask0 = _mm_setr_epi8(0, 0x80, 0x80, 0x80, 1, 0x80, 0x80, 0x80, 2, 0x80, 0x80, 0x80, 3, 0x80, 0x80, 0x80);
    __m128i mask1 = _mm_setr_epi8(4, 0x80, 0x80, 0x80, 5, 0x80, 0x80, 0x80, 6, 0x80, 0x80, 0x80, 7, 0x80, 0x80, 0x80);
    __m128i mask2 = _mm_setr_epi8(8, 0x80, 0x80, 0x80, 9, 0x80, 0x80, 0x80, 10, 0x80, 0x80, 0x80, 11, 0x80, 0x80, 0x80);
    __m128i mask3 = _mm_setr_epi8(12, 0x80, 0x80, 0x80, 13, 0x80, 0x80, 0x80, 14, 0x80, 0x80, 0x80, 15, 0x80, 0x80, 0x80);
    px[0] = _mm_loadu_si128((__m128i *)srcPtrR);    /* load [R01|R02|R03|R04|R05|R06|R07|R08|R09|R10|R11|R12|R13|R14|R15|R16] */
    px[1] = _mm_loadu_si128((__m128i *)srcPtrG);    /* load [G01|G02|G03|G04|G05|G06|G07|G08|G09|G10|G11|G12|G13|G14|G15|G16] */
    px[2] = _mm_loadu_si128((__m128i *)srcPtrB);    /* load [B01|B02|B03|B04|B05|B06|B07|B08|B09|B10|B11|B12|B13|B14|B15|B16] */
    p[0] = _mm256_cvtepi32_ps(_mm256_setr_m128i(_mm_shuffle_epi8(px[0], mask0), _mm_shuffle_epi8(px[0], mask1)));    /* Contains R01-08 */
    p[1] = _mm256_cvtepi32_ps(_mm256_setr_m128i(_mm_shuffle_epi8(px[0], mask2), _mm_shuffle_epi8(px[0], mask3)));    /* Contains R09-16 */
    p[2] = _mm256_cvtepi32_ps(_mm256_setr_m128i(_mm_shuffle_epi8(px[1], mask0), _mm_shuffle_epi8(px[1], mask1)));    /* Contains G01-08 */
    p[3] = _mm256_cvtepi32_ps(_mm256_setr_m128i(_mm_shuffle_epi8(px[1], mask2), _mm_shuffle_epi8(px[1], mask3)));    /* Contains G09-16 */
    p[4] = _mm256_cvtepi32_ps(_mm256_setr_m128i(_mm_shuffle_epi8(px[2], mask0), _mm_shuffle_epi8(px[2], mask1)));    /* Contains B01-08 */
    p[5] = _mm256_cvtepi32_ps(_mm256_setr_m128i(_mm_shuffle_epi8(px[2], mask2), _mm_shuffle_epi8(px[2], mask3)));    /* Contains B09-16 */

    return RPP_SUCCESS;
}

inline RppStatus rpp_store48_f32pln3_to_u8pkd3_avx(Rpp8u *dstPtr, __m256 *p)
{
    __m256i pxCvt[3];
    __m128i px[5];
    __m128i pxMask = _mm_setr_epi8(0, 4, 8, 1, 5, 9, 2, 6, 10, 3, 7, 11, 12, 13, 14, 15);

    pxCvt[0] = _mm256_cvtps_epi32(p[0]);    /* convert to int32 for R01-08 */
    pxCvt[1] = _mm256_cvtps_epi32(p[2]);    /* convert to int32 for G01-08 */
    pxCvt[2] = _mm256_cvtps_epi32(p[4]);    /* convert to int32 for B01-08 */
    px[3] = _mm_packus_epi32(_mm256_extracti128_si256(pxCvt[0], 0), _mm256_extracti128_si256(pxCvt[1], 0));    /* pack pixels 0-7 as R01-04|G01-04 */
    px[4] = _mm_packus_epi32(_mm256_extracti128_si256(pxCvt[2], 0), xmm_px0);    /* pack pixels 8-15 as B01-04|X01-04 */
    px[0] = _mm_packus_epi16(px[3], px[4]);    /* pack pixels 0-15 as [R01|R02|R03|R04|G01|G02|G03|G04|B01|B02|B03|B04|00|00|00|00] */
    px[3] = _mm_packus_epi32(_mm256_extracti128_si256(pxCvt[0], 1), _mm256_extracti128_si256(pxCvt[1], 1));    /* pack pixels 0-7 as R05-08|G05-08 */
    px[4] = _mm_packus_epi32(_mm256_extracti128_si256(pxCvt[2], 1), xmm_px0);    /* pack pixels 8-15 as B05-08|X05-08 */
    px[1] = _mm_packus_epi16(px[3], px[4]);    /* pack pixels 0-15 as [R05|R06|R07|R08|G05|G06|G07|G08|B05|B06|B07|B08|00|00|00|00] */
    pxCvt[0] = _mm256_cvtps_epi32(p[1]);    /* convert to int32 for R09-16 */
    pxCvt[1] = _mm256_cvtps_epi32(p[3]);    /* convert to int32 for G09-16 */
    pxCvt[2] = _mm256_cvtps_epi32(p[5]);    /* convert to int32 for B09-16 */
    px[3] = _mm_packus_epi32(_mm256_extracti128_si256(pxCvt[0], 0), _mm256_extracti128_si256(pxCvt[1], 0));    /* pack pixels 0-7 as R09-12|G09-12 */
    px[4] = _mm_packus_epi32(_mm256_extracti128_si256(pxCvt[2], 0), xmm_px0);    /* pack pixels 8-15 as B09-12|X09-12 */
    px[2] = _mm_packus_epi16(px[3], px[4]);    /* pack pixels 0-15 as [R09|R10|R11|R12|G09|G10|G11|G12|B09|B10|B11|B12|00|00|00|00] */
    px[3] = _mm_packus_epi32(_mm256_extracti128_si256(pxCvt[0], 1), _mm256_extracti128_si256(pxCvt[1], 1));    /* pack pixels 0-7 as R13-16|G13-16 */
    px[4] = _mm_packus_epi32(_mm256_extracti128_si256(pxCvt[2], 1), xmm_px0);    /* pack pixels 8-15 as B13-16|X13-16 */
    px[3] = _mm_packus_epi16(px[3], px[4]);    /* pack pixels 0-15 as [R13|R14|R15|R16|G13|G14|G15|G16|B13|B14|B15|B16|00|00|00|00] */
    px[0] = _mm_shuffle_epi8(px[0], pxMask);    /* shuffle to get [R01|G01|B01|R02|G02|B02|R03|G03|B03|R04|G04|B04|00|00|00|00] */
    px[1] = _mm_shuffle_epi8(px[1], pxMask);    /* shuffle to get [R05|G05|B05|R06|G06|B06|R07|G07|B07|R08|G08|B08|00|00|00|00] */
    px[2] = _mm_shuffle_epi8(px[2], pxMask);    /* shuffle to get [R09|G09|B09|R10|G10|B10|R11|G11|B11|R12|G12|B12|00|00|00|00] */
    px[3] = _mm_shuffle_epi8(px[3], pxMask);    /* shuffle to get [R13|G13|B13|R14|G14|B14|R15|G15|B15|R16|G16|B16|00|00|00|00] */
    _mm_storeu_si128((__m128i *)dstPtr, px[0]);           /* store [R01|G01|B01|R02|G02|B02|R03|G03|B03|R04|G04|B04|00|00|00|00] */
    _mm_storeu_si128((__m128i *)(dstPtr + 12), px[1]);    /* store [R05|G05|B05|R06|G06|B06|R07|G07|B07|R08|G08|B08|00|00|00|00] */
    _mm_storeu_si128((__m128i *)(dstPtr + 24), px[2]);    /* store [R09|G09|B09|R10|G10|B10|R11|G11|B11|R12|G12|B12|00|00|00|00] */
    _mm_storeu_si128((__m128i *)(dstPtr + 36), px[3]);    /* store [R13|G13|B13|R14|G14|B14|R15|G15|B15|R16|G16|B16|00|00|00|00] */

    return RPP_SUCCESS;
}

inline RppStatus rpp_load16_u8_to_f32_avx(Rpp8u *srcPtr, __m256 *p)
{
    __m128i px;
    px = _mm_loadu_si128((__m128i *)srcPtr);
    p[0] = _mm256_cvtepi32_ps(_mm256_setr_m128i(_mm_shuffle_epi8(px, pxMask0), _mm_shuffle_epi8(px, pxMask1)));    /* Contains pixels 01-08 */
    p[1] = _mm256_cvtepi32_ps(_mm256_setr_m128i(_mm_shuffle_epi8(px, pxMask2), _mm_shuffle_epi8(px, pxMask3)));    /* Contains pixels 09-16 */

    return RPP_SUCCESS;
}

inline RppStatus rpp_store16_f32_to_u8_avx(Rpp8u *dstPtr, __m256 *p)
{
    __m256i pxCvt;
    __m128i px[3];
    pxCvt = _mm256_cvtps_epi32(p[0]);
    px[1] = _mm_packus_epi32(_mm256_extracti128_si256(pxCvt, 0), _mm256_extracti128_si256(pxCvt, 1));    /* pack pixels 0-7 for R */
    pxCvt = _mm256_cvtps_epi32(p[1]);
    px[2] = _mm_packus_epi32(_mm256_extracti128_si256(pxCvt, 0), _mm256_extracti128_si256(pxCvt, 1));    /* pack pixels 8-15 for R */
    px[0] = _mm_packus_epi16(px[1], px[2]);    /* pack pixels 0-15 */
    _mm_storeu_si128((__m128i *)dstPtr, px[0]);

    return RPP_SUCCESS;
}

inline RppStatus rpp_load16_i8_to_f32_avx(Rpp8s *srcPtr, __m256 *p)
{
    __m128i px;
    __m128i pxConvertI8 = _mm_set1_epi8((char)128);
    px = _mm_add_epi8(pxConvertI8, _mm_loadu_si128((__m128i *)srcPtr));    /* add I8 conversion param to load */
    p[0] = _mm256_cvtepi32_ps(_mm256_setr_m128i(_mm_shuffle_epi8(px, pxMask0), _mm_shuffle_epi8(px, pxMask1)));    /* Contains pixels 01-08 */
    p[1] = _mm256_cvtepi32_ps(_mm256_setr_m128i(_mm_shuffle_epi8(px, pxMask2), _mm_shuffle_epi8(px, pxMask3)));    /* Contains pixels 09-16 */

    return RPP_SUCCESS;
}

inline RppStatus rpp_store16_f32_to_i8_avx(Rpp8s *dstPtr, __m256 *p)
{
    __m256i pxCvt;
    __m128i px[3];
    __m128i pxConvertI8 = _mm_set1_epi8((char)128);
    pxCvt = _mm256_cvtps_epi32(p[0]);
    px[1] = _mm_packus_epi32(_mm256_extracti128_si256(pxCvt, 0), _mm256_extracti128_si256(pxCvt, 1));    /* pack pixels 0-7 for R */
    pxCvt = _mm256_cvtps_epi32(p[1]);
    px[2] = _mm_packus_epi32(_mm256_extracti128_si256(pxCvt, 0), _mm256_extracti128_si256(pxCvt, 1));    /* pack pixels 8-15 for R */
    px[0] = _mm_packus_epi16(px[1], px[2]);    /* pack pixels 0-15 */
    px[0] = _mm_sub_epi8(px[0], pxConvertI8);    /* convert back to i8 for px0 store */
    _mm_storeu_si128((__m128i *)dstPtr, px[0]);

    return RPP_SUCCESS;
}

inline RppStatus rpp_load24_f32pkd3_to_f32pln3_avx(Rpp32f *srcPtr, __m256 *p)
{
    __m128 p128[8];
    p128[0] = _mm_loadu_ps(srcPtr);
    p128[1] = _mm_loadu_ps(&srcPtr[3]);
    p128[2] = _mm_loadu_ps(&srcPtr[6]);
    p128[3] = _mm_loadu_ps(&srcPtr[9]);
    _MM_TRANSPOSE4_PS(p128[0], p128[1], p128[2], p128[3]);
    p128[4] = _mm_loadu_ps(&srcPtr[12]);
    p128[5] = _mm_loadu_ps(&srcPtr[15]);
    p128[6] = _mm_loadu_ps(&srcPtr[18]);
    p128[7] = _mm_loadu_ps(&srcPtr[21]);
    _MM_TRANSPOSE4_PS(p128[4], p128[5], p128[6], p128[7]);
    p[0] = _mm256_setr_m128(p128[0], p128[4]);
    p[1] = _mm256_setr_m128(p128[1], p128[5]);
    p[2] = _mm256_setr_m128(p128[2], p128[6]);

    return RPP_SUCCESS;
}

inline RppStatus rpp_store24_f32pln3_to_f32pln3_avx(Rpp32f *dstPtrR, Rpp32f *dstPtrG, Rpp32f *dstPtrB, __m256 *p)
{
    _mm256_storeu_ps(dstPtrR, p[0]);
    _mm256_storeu_ps(dstPtrG, p[1]);
    _mm256_storeu_ps(dstPtrB, p[2]);

    return RPP_SUCCESS;
}

inline RppStatus rpp_load24_f32pln3_to_f32pln3_avx(Rpp32f *srcPtrR, Rpp32f *srcPtrG, Rpp32f *srcPtrB, __m256 *p)
{
    p[0] = _mm256_loadu_ps(srcPtrR);
    p[1] = _mm256_loadu_ps(srcPtrG);
    p[2] = _mm256_loadu_ps(srcPtrB);

    return RPP_SUCCESS;
}

inline RppStatus rpp_store24_f32pln3_to_f32pkd3_avx(Rpp32f *dstPtr, __m256 *p)
{
    __m128 p128[8];
    p128[0] = _mm256_extractf128_ps(p[0], 0);
    p128[1] = _mm256_extractf128_ps(p[1], 0);
    p128[2] = _mm256_extractf128_ps(p[2], 0);
    _MM_TRANSPOSE4_PS(p128[0], p128[1], p128[2], p128[3]);
    _mm_storeu_ps(dstPtr, p128[0]);
    _mm_storeu_ps(&dstPtr[3], p128[1]);
    _mm_storeu_ps(&dstPtr[6], p128[2]);
    _mm_storeu_ps(&dstPtr[9], p128[3]);
    p128[0] = _mm256_extractf128_ps(p[0], 1);
    p128[1] = _mm256_extractf128_ps(p[1], 1);
    p128[2] = _mm256_extractf128_ps(p[2], 1);
    _MM_TRANSPOSE4_PS(p128[0], p128[1], p128[2], p128[3]);
    _mm_storeu_ps(&dstPtr[12], p128[0]);
    _mm_storeu_ps(&dstPtr[15], p128[1]);
    _mm_storeu_ps(&dstPtr[18], p128[2]);
    _mm_storeu_ps(&dstPtr[21], p128[3]);

    return RPP_SUCCESS;
}

inline RppStatus rpp_load8_f32_to_f32_avx(Rpp32f *srcPtr, __m256 *p)
{
    p[0] = _mm256_loadu_ps(srcPtr);

    return RPP_SUCCESS;
}

inline RppStatus rpp_store8_f32_to_f32_avx(Rpp32f *dstPtr, __m256 *p)
{
    _mm256_storeu_ps(dstPtr, p[0]);

    return RPP_SUCCESS;
}

inline RppStatus rpp_load16_f32_to_f32_avx(Rpp32f *srcPtr, __m256 *p)
{
    p[0] = _mm256_loadu_ps(srcPtr);
    p[1] = _mm256_loadu_ps(&srcPtr[8]);

    return RPP_SUCCESS;
}

inline RppStatus rpp_load48_i8pkd3_to_f32pln3_avx(Rpp8s *srcPtr, __m256 *p)
{
    __m128i px[4];
    __m128i pxConvertI8 = _mm_set1_epi8((char)128);
    __m128i maskR = _mm_setr_epi8(0, 0x80, 0x80, 0x80, 3, 0x80, 0x80, 0x80, 6, 0x80, 0x80, 0x80, 9, 0x80, 0x80, 0x80);
    __m128i maskG = _mm_setr_epi8(1, 0x80, 0x80, 0x80, 4, 0x80, 0x80, 0x80, 7, 0x80, 0x80, 0x80, 10, 0x80, 0x80, 0x80);
    __m128i maskB = _mm_setr_epi8(2, 0x80, 0x80, 0x80, 5, 0x80, 0x80, 0x80, 8, 0x80, 0x80, 0x80, 11, 0x80, 0x80, 0x80);
    px[0] = _mm_add_epi8(pxConvertI8, _mm_loadu_si128((__m128i *)srcPtr));           /* add I8 conversion param to load [R01|G01|B01|R02|G02|B02|R03|G03|B03|R04|G04|B04|R05|G05|B05|R06] - Need RGB 01-04 */
    px[1] = _mm_add_epi8(pxConvertI8, _mm_loadu_si128((__m128i *)(srcPtr + 12)));    /* add I8 conversion param to load [R05|G05|B05|R06|G06|B06|R07|G07|B07|R08|G08|B08|R09|G09|B09|R10] - Need RGB 05-08 */
    px[2] = _mm_add_epi8(pxConvertI8, _mm_loadu_si128((__m128i *)(srcPtr + 24)));    /* add I8 conversion param to load [R09|G09|B09|R10|G10|B10|R11|G11|B11|R12|G12|B12|R13|G13|B13|R14] - Need RGB 09-12 */
    px[3] = _mm_add_epi8(pxConvertI8, _mm_loadu_si128((__m128i *)(srcPtr + 36)));    /* add I8 conversion param to load [R13|G13|B13|R14|G14|B14|R15|G15|B15|R16|G16|B16|R17|G17|B17|R18] - Need RGB 13-16 */
    p[0] = _mm256_cvtepi32_ps(_mm256_setr_m128i(_mm_shuffle_epi8(px[0], maskR), _mm_shuffle_epi8(px[1], maskR)));    /* Contains R01-08 */
    p[1] = _mm256_cvtepi32_ps(_mm256_setr_m128i(_mm_shuffle_epi8(px[2], maskR), _mm_shuffle_epi8(px[3], maskR)));    /* Contains R09-16 */
    p[2] = _mm256_cvtepi32_ps(_mm256_setr_m128i(_mm_shuffle_epi8(px[0], maskG), _mm_shuffle_epi8(px[1], maskG)));    /* Contains G01-08 */
    p[3] = _mm256_cvtepi32_ps(_mm256_setr_m128i(_mm_shuffle_epi8(px[2], maskG), _mm_shuffle_epi8(px[3], maskG)));    /* Contains G09-16 */
    p[4] = _mm256_cvtepi32_ps(_mm256_setr_m128i(_mm_shuffle_epi8(px[0], maskB), _mm_shuffle_epi8(px[1], maskB)));    /* Contains B01-08 */
    p[5] = _mm256_cvtepi32_ps(_mm256_setr_m128i(_mm_shuffle_epi8(px[2], maskB), _mm_shuffle_epi8(px[3], maskB)));    /* Contains B09-16 */

    return RPP_SUCCESS;
}

inline RppStatus rpp_store48_f32pln3_to_i8pln3_avx(Rpp8s *dstPtrR, Rpp8s *dstPtrG, Rpp8s *dstPtrB, __m256 *p)
{
    __m256i pxCvt;
    __m128i px[4];
    __m128i pxConvertI8 = _mm_set1_epi8((char)128);

    pxCvt = _mm256_cvtps_epi32(p[0]);
    px[2] = _mm_packus_epi32(_mm256_extracti128_si256(pxCvt, 0), _mm256_extracti128_si256(pxCvt, 1));    /* pack pixels 0-7 for R */
    pxCvt = _mm256_cvtps_epi32(p[1]);
    px[3] = _mm_packus_epi32(_mm256_extracti128_si256(pxCvt, 0), _mm256_extracti128_si256(pxCvt, 1));    /* pack pixels 8-15 for R */
    px[0] = _mm_packus_epi16(px[2], px[3]);    /* pack pixels 0-15 for R */
    pxCvt = _mm256_cvtps_epi32(p[2]);
    px[2] = _mm_packus_epi32(_mm256_extracti128_si256(pxCvt, 0), _mm256_extracti128_si256(pxCvt, 1));    /* pack pixels 0-7 for G */
    pxCvt = _mm256_cvtps_epi32(p[3]);
    px[3] = _mm_packus_epi32(_mm256_extracti128_si256(pxCvt, 0), _mm256_extracti128_si256(pxCvt, 1));    /* pack pixels 8-15 for G */
    px[1] = _mm_packus_epi16(px[2], px[3]);    /* pack pixels 0-15 for G */
    pxCvt = _mm256_cvtps_epi32(p[4]);
    px[2] = _mm_packus_epi32(_mm256_extracti128_si256(pxCvt, 0), _mm256_extracti128_si256(pxCvt, 1));    /* pack pixels 0-7 for B */
    pxCvt = _mm256_cvtps_epi32(p[5]);
    px[3] = _mm_packus_epi32(_mm256_extracti128_si256(pxCvt, 0), _mm256_extracti128_si256(pxCvt, 1));    /* pack pixels 8-15 for B */
    px[2] = _mm_packus_epi16(px[2], px[3]);    /* pack pixels 0-15 for B */
    px[0] = _mm_sub_epi8(px[0], pxConvertI8);    /* convert back to i8 for px0 store */
    px[1] = _mm_sub_epi8(px[1], pxConvertI8);    /* convert back to i8 for px1 store */
    px[2] = _mm_sub_epi8(px[2], pxConvertI8);    /* convert back to i8 for px2 store */
    _mm_storeu_si128((__m128i *)dstPtrR, px[0]);    /* store [R01|R02|R03|R04|R05|R06|R07|R08|R09|R10|R11|R12|R13|R14|R15|R16] */
    _mm_storeu_si128((__m128i *)dstPtrG, px[1]);    /* store [G01|G02|G03|G04|G05|G06|G07|G08|G09|G10|G11|G12|G13|G14|G15|G16] */
    _mm_storeu_si128((__m128i *)dstPtrB, px[2]);    /* store [B01|B02|B03|B04|B05|B06|B07|B08|B09|B10|B11|B12|B13|B14|B15|B16] */

    return RPP_SUCCESS;
}

inline RppStatus rpp_load48_i8pln3_to_f32pln3_avx(Rpp8s *srcPtrR, Rpp8s *srcPtrG, Rpp8s *srcPtrB, __m256 *p)
{
    __m128i px[3];
    __m128i pxConvertI8 = _mm_set1_epi8((char)128);
    __m128i mask0 = _mm_setr_epi8(0, 0x80, 0x80, 0x80, 1, 0x80, 0x80, 0x80, 2, 0x80, 0x80, 0x80, 3, 0x80, 0x80, 0x80);
    __m128i mask1 = _mm_setr_epi8(4, 0x80, 0x80, 0x80, 5, 0x80, 0x80, 0x80, 6, 0x80, 0x80, 0x80, 7, 0x80, 0x80, 0x80);
    __m128i mask2 = _mm_setr_epi8(8, 0x80, 0x80, 0x80, 9, 0x80, 0x80, 0x80, 10, 0x80, 0x80, 0x80, 11, 0x80, 0x80, 0x80);
    __m128i mask3 = _mm_setr_epi8(12, 0x80, 0x80, 0x80, 13, 0x80, 0x80, 0x80, 14, 0x80, 0x80, 0x80, 15, 0x80, 0x80, 0x80);
    px[0] = _mm_add_epi8(pxConvertI8, _mm_loadu_si128((__m128i *)srcPtrR));    /* add I8 conversion param to load [R01|R02|R03|R04|R05|R06|R07|R08|R09|R10|R11|R12|R13|R14|R15|R16] */
    px[1] = _mm_add_epi8(pxConvertI8, _mm_loadu_si128((__m128i *)srcPtrG));    /* add I8 conversion param to load [G01|G02|G03|G04|G05|G06|G07|G08|G09|G10|G11|G12|G13|G14|G15|G16] */
    px[2] = _mm_add_epi8(pxConvertI8, _mm_loadu_si128((__m128i *)srcPtrB));    /* add I8 conversion param to load [B01|B02|B03|B04|B05|B06|B07|B08|B09|B10|B11|B12|B13|B14|B15|B16] */
    p[0] = _mm256_cvtepi32_ps(_mm256_setr_m128i(_mm_shuffle_epi8(px[0], mask0), _mm_shuffle_epi8(px[0], mask1)));    /* Contains R01-08 */
    p[1] = _mm256_cvtepi32_ps(_mm256_setr_m128i(_mm_shuffle_epi8(px[0], mask2), _mm_shuffle_epi8(px[0], mask3)));    /* Contains R09-16 */
    p[2] = _mm256_cvtepi32_ps(_mm256_setr_m128i(_mm_shuffle_epi8(px[1], mask0), _mm_shuffle_epi8(px[1], mask1)));    /* Contains G01-08 */
    p[3] = _mm256_cvtepi32_ps(_mm256_setr_m128i(_mm_shuffle_epi8(px[1], mask2), _mm_shuffle_epi8(px[1], mask3)));    /* Contains G09-16 */
    p[4] = _mm256_cvtepi32_ps(_mm256_setr_m128i(_mm_shuffle_epi8(px[2], mask0), _mm_shuffle_epi8(px[2], mask1)));    /* Contains B01-08 */
    p[5] = _mm256_cvtepi32_ps(_mm256_setr_m128i(_mm_shuffle_epi8(px[2], mask2), _mm_shuffle_epi8(px[2], mask3)));    /* Contains B09-16 */

    return RPP_SUCCESS;
}

inline RppStatus rpp_store48_f32pln3_to_i8pkd3_avx(Rpp8s *dstPtr, __m256 *p)
{
    __m256i pxCvt[3];
    __m128i px[5];
    __m128i pxMask = _mm_setr_epi8(0, 4, 8, 1, 5, 9, 2, 6, 10, 3, 7, 11, 12, 13, 14, 15);
    __m128i pxConvertI8 = _mm_set1_epi8((char)128);

    pxCvt[0] = _mm256_cvtps_epi32(p[0]);    /* convert to int32 for R01-08 */
    pxCvt[1] = _mm256_cvtps_epi32(p[2]);    /* convert to int32 for G01-08 */
    pxCvt[2] = _mm256_cvtps_epi32(p[4]);    /* convert to int32 for B01-08 */
    px[3] = _mm_packus_epi32(_mm256_extracti128_si256(pxCvt[0], 0), _mm256_extracti128_si256(pxCvt[1], 0));    /* pack pixels 0-7 as R01-04|G01-04 */
    px[4] = _mm_packus_epi32(_mm256_extracti128_si256(pxCvt[2], 0), xmm_px0);    /* pack pixels 8-15 as B01-04|X01-04 */
    px[0] = _mm_packus_epi16(px[3], px[4]);    /* pack pixels 0-15 as [R01|R02|R03|R04|G01|G02|G03|G04|B01|B02|B03|B04|00|00|00|00] */
    px[3] = _mm_packus_epi32(_mm256_extracti128_si256(pxCvt[0], 1), _mm256_extracti128_si256(pxCvt[1], 1));    /* pack pixels 0-7 as R05-08|G05-08 */
    px[4] = _mm_packus_epi32(_mm256_extracti128_si256(pxCvt[2], 1), xmm_px0);    /* pack pixels 8-15 as B05-08|X05-08 */
    px[1] = _mm_packus_epi16(px[3], px[4]);    /* pack pixels 0-15 as [R05|R06|R07|R08|G05|G06|G07|G08|B05|B06|B07|B08|00|00|00|00] */
    pxCvt[0] = _mm256_cvtps_epi32(p[1]);    /* convert to int32 for R09-16 */
    pxCvt[1] = _mm256_cvtps_epi32(p[3]);    /* convert to int32 for G09-16 */
    pxCvt[2] = _mm256_cvtps_epi32(p[5]);    /* convert to int32 for B09-16 */
    px[3] = _mm_packus_epi32(_mm256_extracti128_si256(pxCvt[0], 0), _mm256_extracti128_si256(pxCvt[1], 0));    /* pack pixels 0-7 as R09-12|G09-12 */
    px[4] = _mm_packus_epi32(_mm256_extracti128_si256(pxCvt[2], 0), xmm_px0);    /* pack pixels 8-15 as B09-12|X09-12 */
    px[2] = _mm_packus_epi16(px[3], px[4]);    /* pack pixels 0-15 as [R09|R10|R11|R12|G09|G10|G11|G12|B09|B10|B11|B12|00|00|00|00] */
    px[3] = _mm_packus_epi32(_mm256_extracti128_si256(pxCvt[0], 1), _mm256_extracti128_si256(pxCvt[1], 1));    /* pack pixels 0-7 as R13-16|G13-16 */
    px[4] = _mm_packus_epi32(_mm256_extracti128_si256(pxCvt[2], 1), xmm_px0);    /* pack pixels 8-15 as B13-16|X13-16 */
    px[3] = _mm_packus_epi16(px[3], px[4]);    /* pack pixels 0-15 as [R13|R14|R15|R16|G13|G14|G15|G16|B13|B14|B15|B16|00|00|00|00] */
    px[0] = _mm_sub_epi8(px[0], pxConvertI8);    /* convert back to i8 for px0 store */
    px[1] = _mm_sub_epi8(px[1], pxConvertI8);    /* convert back to i8 for px1 store */
    px[2] = _mm_sub_epi8(px[2], pxConvertI8);    /* convert back to i8 for px2 store */
    px[3] = _mm_sub_epi8(px[3], pxConvertI8);    /* convert back to i8 for px3 store */
    px[0] = _mm_shuffle_epi8(px[0], pxMask);    /* shuffle to get [R01|G01|B01|R02|G02|B02|R03|G03|B03|R04|G04|B04|00|00|00|00] */
    px[1] = _mm_shuffle_epi8(px[1], pxMask);    /* shuffle to get [R05|G05|B05|R06|G06|B06|R07|G07|B07|R08|G08|B08|00|00|00|00] */
    px[2] = _mm_shuffle_epi8(px[2], pxMask);    /* shuffle to get [R09|G09|B09|R10|G10|B10|R11|G11|B11|R12|G12|B12|00|00|00|00] */
    px[3] = _mm_shuffle_epi8(px[3], pxMask);    /* shuffle to get [R13|G13|B13|R14|G14|B14|R15|G15|B15|R16|G16|B16|00|00|00|00] */
    _mm_storeu_si128((__m128i *)dstPtr, px[0]);           /* store [R01|G01|B01|R02|G02|B02|R03|G03|B03|R04|G04|B04|00|00|00|00] */
    _mm_storeu_si128((__m128i *)(dstPtr + 12), px[1]);    /* store [R05|G05|B05|R06|G06|B06|R07|G07|B07|R08|G08|B08|00|00|00|00] */
    _mm_storeu_si128((__m128i *)(dstPtr + 24), px[2]);    /* store [R09|G09|B09|R10|G10|B10|R11|G11|B11|R12|G12|B12|00|00|00|00] */
    _mm_storeu_si128((__m128i *)(dstPtr + 36), px[3]);    /* store [R13|G13|B13|R14|G14|B14|R15|G15|B15|R16|G16|B16|00|00|00|00] */

    return RPP_SUCCESS;
}

inline RppStatus rpp_normalize48_avx(__m256 *p)
{
    p[0] = _mm256_mul_ps(p[0], avx_p1op255);
    p[1] = _mm256_mul_ps(p[1], avx_p1op255);
    p[2] = _mm256_mul_ps(p[2], avx_p1op255);
    p[3] = _mm256_mul_ps(p[3], avx_p1op255);
    p[4] = _mm256_mul_ps(p[4], avx_p1op255);
    p[5] = _mm256_mul_ps(p[5], avx_p1op255);

    return RPP_SUCCESS;
}

template <typename FuncType, typename... ArgTypes>
inline RppStatus rpp_simd_load(FuncType &&rpp_simd_load_routine, ArgTypes&&... args)
{
    std::forward<FuncType>(rpp_simd_load_routine)(std::forward<ArgTypes>(args)...);

    return RPP_SUCCESS;
}

template <typename FuncType, typename... ArgTypes>
inline RppStatus rpp_simd_store(FuncType &&rpp_simd_store_routine, ArgTypes&&... args)
{
    std::forward<FuncType>(rpp_simd_store_routine)(std::forward<ArgTypes>(args)...);

    return RPP_SUCCESS;
}

// Shuffle floats in `src` by using SSE2 `pshufd` instead of `shufps`, if possible.
#define SIMD_SHUFFLE_PS(src, imm) \
    _mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(src), imm))

#define CHECK_SIMD  0
#define FP_BITS     16
#define FP_MUL      (1<<FP_BITS)

const __m128 xmm_full = _mm_set1_ps((float)0xFFFFFFFF);
const __m128 xmm_sn = _mm_castsi128_ps(_mm_set1_epi32(0x80000000));
const __m128 xmm_m6 = _mm_set1_ps((float)-6.0);
const __m128 xmm_eps = _mm_set1_ps((float)1e-9f);
const __m128 xmm_1o3 = _mm_set1_ps((float)1.0/3.0);
const __m128 xmm_m4o6 = _mm_set1_ps((float) -4.0/6.0);
const __m128 xmm_abs = _mm_set1_ps((float)0x80000000);

const __m128 xmm_4o6_2o6_3o6_0  = _mm_set_ps(4.0f / 6.0f, 2.0f / 6.0f, 3.0f / 6.0f, 0.0f);
const __m128 m6_m6_p6_p0        = _mm_set_ps(-6.0f ,-6.0f , 6.0f , 0.0f);
const __m128 p1_p1_m2_p0        = _mm_set_ps(1.0f , 1.0f ,-2.0f , 0.0f);
const __m128 m1_m1_m1_p1        = _mm_set_ps(-1.0f ,-1.0f ,-1.0f , 1.0f);


SIMD_CONST_PI(full       , 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF);
SIMD_CONST_PI(sn         , 0x80000000, 0x80000000, 0x80000000, 0x80000000);
SIMD_CONST_PS(m6_m6_m6_m6,-6.0f ,-6.0f ,-6.0f ,-6.0f);
SIMD_CONST_PS(m4o6_m4o6_m4o6_m4o6,-4.0f / 6.0f,-4.0f / 6.0f,-4.0f / 6.0f,-4.0f / 6.0f);
SIMD_CONST_PS(eps        , 1e-9f, 1e-9f, 1e-9f, 1e-9f);
SIMD_CONST_PS(p1         , 1.0f , 1.0f , 1.0f , 1.0f);

SIMD_CONST_PS(p4o6_p2o6_p3o6_p0  , 4.0f / 6.0f, 2.0f / 6.0f, 3.0f / 6.0f, 0.0f);
SIMD_CONST_PI(abs        , 0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF);
SIMD_CONST_PS(m6_m6_p6_p0,-6.0f ,-6.0f , 6.0f , 0.0f);
SIMD_CONST_PS(p1_p1_m2_p0, 1.0f , 1.0f ,-2.0f , 0.0f);
SIMD_CONST_PS(m1_m1_m1_p1,-1.0f ,-1.0f ,-1.0f , 1.0f);
SIMD_CONST_PS(p0         , 0.0f , 0.0f , 0.0f , 0.0f);

inline __m128i _mm_mullo_epi8(__m128i a, __m128i b)
{
    __m128i zero = _mm_setzero_si128();
    __m128i Alo = _mm_cvtepu8_epi16(a);
    __m128i Ahi = _mm_unpackhi_epi8(a, zero);
    __m128i Blo = _mm_cvtepu8_epi16(b);
    __m128i Bhi = _mm_unpackhi_epi8(b, zero);
    __m128i Clo = _mm_mullo_epi16(Alo, Blo);
    __m128i Chi = _mm_mullo_epi16(Ahi, Bhi);
    __m128i maskLo = _mm_set_epi8(0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 14, 12, 10, 8, 6, 4, 2, 0);
    __m128i maskHi = _mm_set_epi8(14, 12, 10, 8, 6, 4, 2, 0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80);
    __m128i C = _mm_or_si128(_mm_shuffle_epi8(Clo, maskLo), _mm_shuffle_epi8(Chi, maskHi));

     return C;
}

static inline Rpp32u HorMin(__m128i pmin)
{
    pmin = _mm_min_epu8(pmin, _mm_shuffle_epi32(pmin, _MM_SHUFFLE(3, 2, 3, 2)));
    pmin = _mm_min_epu8(pmin, _mm_shuffle_epi32(pmin, _MM_SHUFFLE(1, 1, 1, 1)));
    pmin = _mm_min_epu8(pmin, _mm_shufflelo_epi16(pmin, _MM_SHUFFLE(1, 1, 1, 1)));
    pmin = _mm_min_epu8(pmin, _mm_srli_epi16(pmin, 8));
    return (_mm_cvtsi128_si32(pmin) & 0x000000FF);
}

static inline Rpp32u HorMax(__m128i pmax)
{
    pmax = _mm_min_epu8(pmax, _mm_shuffle_epi32(pmax, _MM_SHUFFLE(3, 2, 3, 2)));
    pmax = _mm_min_epu8(pmax, _mm_shuffle_epi32(pmax, _MM_SHUFFLE(1, 1, 1, 1)));
    pmax = _mm_min_epu8(pmax, _mm_shufflelo_epi16(pmax, _MM_SHUFFLE(1, 1, 1, 1)));
    pmax = _mm_min_epu8(pmax, _mm_srli_epi16(pmax, 8));
    return (_mm_cvtsi128_si32(pmax) & 0x000000FF);
}

#if __AVX__
static inline Rpp32u HorMin256(__m256i pmin)
{
    __m128i pmin_128;
    pmin = _mm256_min_epu8(pmin, _mm256_permute4x64_epi64(pmin, _MM_SHUFFLE(3, 2, 3, 2)));
    pmin = _mm256_min_epu8(pmin, _mm256_permute4x64_epi64(pmin, _MM_SHUFFLE(1, 1, 1, 1)));
    pmin_128 = M256I(pmin).m256i_i128[0];
    pmin_128 = _mm_min_epu8(pmin_128, _mm_shufflelo_epi16(pmin_128, _MM_SHUFFLE(1, 1, 1, 1)));
    pmin_128 = _mm_min_epu8(pmin_128, _mm_srli_epi16(pmin_128, 8));
    return (_mm_cvtsi128_si32(pmin_128) & 0x000000FF);
}

static inline Rpp32u HorMax256(__m256i pmax)
{
    __m128i pmax_128;
    pmax = _mm256_max_epu8(pmax, _mm256_permute4x64_epi64(pmax, _MM_SHUFFLE(3, 2, 3, 2)));
    pmax = _mm256_max_epu8(pmax, _mm256_permute4x64_epi64(pmax, _MM_SHUFFLE(1, 1, 1, 1)));
    pmax_128 = M256I(pmax).m256i_i128[0];
    pmax_128 = _mm_max_epi8(pmax_128, _mm_shufflelo_epi16(pmax_128, _MM_SHUFFLE(1, 1, 1, 1)));
    pmax_128 = _mm_max_epi8(pmax_128, _mm_srli_epi16(pmax_128, 8));
    return (_mm_cvtsi128_si32(pmax_128) & 0x000000FF);
}
#endif

static  inline __m128 fast_exp_sse (__m128 x)
{
    __m128 t, f, e, p, r;
    __m128i i, j;
    __m128 l2e = _mm_set1_ps (1.442695041f);  /* log2(e) */
    __m128 c0  = _mm_set1_ps (0.3371894346f);
    __m128 c1  = _mm_set1_ps (0.657636276f);
    __m128 c2  = _mm_set1_ps (1.00172476f);

    /* exp(x) = 2^i * 2^f; i = floor (log2(e) * x), 0 <= f <= 1 */
    t = _mm_mul_ps (x, l2e);             /* t = log2(e) * x */
#ifdef __SSE4_1__
    e = _mm_floor_ps (t);                /* floor(t) */
    i = _mm_cvtps_epi32 (e);             /* (int)floor(t) */
#else /* __SSE4_1__*/
    i = _mm_cvttps_epi32 (t);            /* i = (int)t */
    j = _mm_srli_epi32 (_mm_castps_si128 (x), 31); /* signbit(t) */
    i = _mm_sub_epi32 (i, j);            /* (int)t - signbit(t) */
    e = _mm_cvtepi32_ps (i);             /* floor(t) ~= (int)t - signbit(t) */
#endif /* __SSE4_1__*/
    f = _mm_sub_ps (t, e);               /* f = t - floor(t) */
    p = c0;                              /* c0 */
    p = _mm_mul_ps (p, f);               /* c0 * f */
    p = _mm_add_ps (p, c1);              /* c0 * f + c1 */
    p = _mm_mul_ps (p, f);               /* (c0 * f + c1) * f */
    p = _mm_add_ps (p, c2);              /* p = (c0 * f + c1) * f + c2 ~= 2^f */
    j = _mm_slli_epi32 (i, 23);          /* i << 23 */
    r = _mm_castsi128_ps (_mm_add_epi32 (j, _mm_castps_si128 (p))); /* r = p * 2^i*/
    return r;
}

#define set1_ps_hex(x) _mm_castsi128_ps(_mm_set1_epi32(x))

static const __m128 _ps_0 = _mm_set1_ps(0.f);
static const __m128 _ps_1 = _mm_set1_ps(1.f);
static const __m128 _ps_0p5 = _mm_set1_ps(0.5f);
static const __m128 _ps_min_norm_pos = set1_ps_hex(0x00800000);
static const __m128 _ps_mant_mask = set1_ps_hex(0x7f800000);
static const __m128 _ps_inv_mant_mask = set1_ps_hex(~0x7f800000);
static const __m128 _ps_sign_mask = set1_ps_hex(0x80000000);
static const __m128 _ps_inv_sign_mask = set1_ps_hex(~0x80000000);

static const __m128i _pi32_1 = _mm_set1_epi32(1);
static const __m128i _pi32_inv1 = _mm_set1_epi32(~1);
static const __m128i _pi32_2 = _mm_set1_epi32(2);
static const __m128i _pi32_4 = _mm_set1_epi32(4);
static const __m128i _pi32_0x7f = _mm_set1_epi32(0x7f);

static const __m128 _ps_minus_cephes_DP1 = _mm_set1_ps(-0.78515625f);
static const __m128 _ps_minus_cephes_DP2 = _mm_set1_ps(-2.4187564849853515625e-4f);
static const __m128 _ps_minus_cephes_DP3 = _mm_set1_ps(-3.77489497744594108e-8f);
static const __m128 _ps_sincof_p0 = _mm_set1_ps(-1.9515295891E-4f);
static const __m128 _ps_sincof_p1 = _mm_set1_ps( 8.3321608736E-3f);
static const __m128 _ps_sincof_p2 = _mm_set1_ps(-1.6666654611E-1f);
static const __m128 _ps_coscof_p0 = _mm_set1_ps( 2.443315711809948E-005f);
static const __m128 _ps_coscof_p1 = _mm_set1_ps(-1.388731625493765E-003f);
static const __m128 _ps_coscof_p2 = _mm_set1_ps( 4.166664568298827E-002f);
static const __m128 _ps_cephes_FOPI = _mm_set1_ps(1.27323954473516f); // 4 / M_PI

static inline void sincos_ps(__m128 x, __m128 *s, __m128 *c)
{
    // Extract the sign bit (upper one)
    __m128 sign_bit_sin = _mm_and_ps(x, _ps_sign_mask);
    // take the absolute value
    x = _mm_xor_ps(x, sign_bit_sin);

    // Scale by 4/Pi
    __m128 y = _mm_mul_ps(x, _ps_cephes_FOPI);

    // Store the integer part of y in emm2
    __m128i emm2 = _mm_cvttps_epi32(y);

    // j=(j+1) & (~1) (see the cephes sources)
    emm2 = _mm_add_epi32(emm2, _pi32_1);
    emm2 = _mm_and_si128(emm2, _pi32_inv1);
    y = _mm_cvtepi32_ps(emm2);

    __m128i emm4 = emm2;

    // Get the swap sign flag for the sine
    __m128i emm0 = _mm_and_si128(emm2, _pi32_4);
    emm0 = _mm_slli_epi32(emm0, 29);
    __m128 swap_sign_bit_sin = _mm_castsi128_ps(emm0);

    // Get the polynom selection mask for the sine
    emm2 = _mm_and_si128(emm2, _pi32_2);
    emm2 = _mm_cmpeq_epi32(emm2, _mm_setzero_si128());
    __m128 poly_mask = _mm_castsi128_ps(emm2);
    // The magic pass: "Extended precision modular arithmetic - x = ((x - y * DP1) - y * DP2) - y * DP3;
    __m128 xmm1 = _mm_mul_ps(y, _ps_minus_cephes_DP1);
    __m128 xmm2 = _mm_mul_ps(y, _ps_minus_cephes_DP2);
    __m128 xmm3 = _mm_mul_ps(y, _ps_minus_cephes_DP3);
    x = _mm_add_ps(_mm_add_ps(x, xmm1), _mm_add_ps(xmm2, xmm3));

    emm4 = _mm_sub_epi32(emm4, _pi32_2);
    emm4 = _mm_andnot_si128(emm4, _pi32_4);
    emm4 = _mm_slli_epi32(emm4, 29);
    __m128 sign_bit_cos = _mm_castsi128_ps(emm4);

    sign_bit_sin = _mm_xor_ps(sign_bit_sin, swap_sign_bit_sin);

    // Evaluate the first polynom  (0 <= x <= Pi/4)
    __m128 z = _mm_mul_ps(x,x);
    y = _ps_coscof_p0;

    y = _mm_mul_ps(y, z);
    y = _mm_add_ps(y, _ps_coscof_p1);
    y = _mm_mul_ps(y, z);
    y = _mm_add_ps(y, _ps_coscof_p2);
    y = _mm_mul_ps(y, _mm_mul_ps(z, z));
    __m128 tmp = _mm_mul_ps(z, _ps_0p5);
    y = _mm_sub_ps(y, tmp);
    y = _mm_add_ps(y, _ps_1);

    // Evaluate the second polynom  (Pi/4 <= x <= 0)

    __m128 y2 = _ps_sincof_p0;
    y2 = _mm_mul_ps(y2, z);
    y2 = _mm_add_ps(y2, _ps_sincof_p1);
    y2 = _mm_mul_ps(y2, z);
    y2 = _mm_add_ps(y2, _ps_sincof_p2);
    y2 = _mm_mul_ps(y2, _mm_mul_ps(z, x));
    y2 = _mm_add_ps(y2, x);

    // Select the correct result from the two polynoms
    xmm3 = poly_mask;
    __m128 ysin2 = _mm_and_ps(xmm3, y2);
    __m128 ysin1 = _mm_andnot_ps(xmm3, y);
    y2 = _mm_sub_ps(y2,ysin2);
    y = _mm_sub_ps(y, ysin1);

    xmm1 = _mm_add_ps(ysin1,ysin2);
    xmm2 = _mm_add_ps(y,y2);

    // Update the sign
    *s = _mm_xor_ps(xmm1, sign_bit_sin);
    *c = _mm_xor_ps(xmm2, sign_bit_cos);
}

static const __m128 _ps_atanrange_hi = _mm_set1_ps(2.414213562373095);
static const __m128 _ps_atanrange_lo = _mm_set1_ps(0.4142135623730950);
static const __m128 _ps_cephes_PIF = _mm_set1_ps(3.141592653589793238);
static const __m128 _ps_cephes_PIO2F = _mm_set1_ps(1.5707963267948966192);
static const __m128 _ps_cephes_PIO4F = _mm_set1_ps(0.7853981633974483096);

static const __m128 _ps_atancof_p0 = _mm_set1_ps(8.05374449538e-2);
static const __m128 _ps_atancof_p1 = _mm_set1_ps(1.38776856032E-1);
static const __m128 _ps_atancof_p2 = _mm_set1_ps(1.99777106478E-1);
static const __m128 _ps_atancof_p3 = _mm_set1_ps(3.33329491539E-1);

static inline __m128 atan_ps( __m128 x )
{
    __m128 sign_bit, y;

    sign_bit = x;
    // Take the absolute value
    x = _mm_and_ps( x, _ps_inv_sign_mask );
    // Extract the sign bit (upper one)
    sign_bit = _mm_and_ps( sign_bit, _ps_sign_mask );

    // Range reduction, init x and y depending on range

    // x > 2.414213562373095
    __m128 cmp0 = _mm_cmpgt_ps( x, _ps_atanrange_hi );
    // x > 0.4142135623730950
    __m128 cmp1 = _mm_cmpgt_ps( x, _ps_atanrange_lo );

    // x > 0.4142135623730950 && !( x > 2.414213562373095 )
    __m128 cmp2 = _mm_andnot_ps( cmp0, cmp1 );

    // -( 1.0/x )
    __m128 y0 = _mm_and_ps( cmp0, _ps_cephes_PIO2F );
    __m128 x0 = _mm_div_ps( _ps_1, x );
    x0 = _mm_xor_ps( x0, _ps_sign_mask );

    __m128 y1 = _mm_and_ps( cmp2, _ps_cephes_PIO4F );
    // (x-1.0)/(x+1.0)
    __m128 x1_o = _mm_sub_ps( x, _ps_1 );
    __m128 x1_u = _mm_add_ps( x, _ps_1 );
    __m128 x1 = _mm_div_ps( x1_o, x1_u );

    __m128 x2 = _mm_and_ps( cmp2, x1 );
    x0 = _mm_and_ps( cmp0, x0 );
    x2 = _mm_or_ps( x2, x0 );
    cmp1 = _mm_or_ps( cmp0, cmp2 );
    x2 = _mm_and_ps( cmp1, x2 );
    x = _mm_andnot_ps( cmp1, x );
    x = _mm_or_ps( x2, x );

    y = _mm_or_ps( y0, y1 );

    __m128 zz = _mm_mul_ps( x, x );
    __m128 acc = _ps_atancof_p0;
    acc = _mm_mul_ps( acc, zz );
    acc = _mm_sub_ps( acc, _ps_atancof_p1 );
    acc = _mm_mul_ps( acc, zz );
    acc = _mm_add_ps( acc, _ps_atancof_p2 );
    acc = _mm_mul_ps( acc, zz );
    acc = _mm_sub_ps( acc, _ps_atancof_p3 );
    acc = _mm_mul_ps( acc, zz );
    acc = _mm_mul_ps( acc, x );
    acc = _mm_add_ps( acc, x );
    y = _mm_add_ps( y, acc );

    // Update the sign
    y = _mm_xor_ps( y, sign_bit );

    return y;
}

static inline __m128 atan2_ps( __m128 y, __m128 x )
{
    __m128 x_eq_0 = _mm_cmpeq_ps( x, _ps_0 );
    __m128 x_gt_0 = _mm_cmpgt_ps( x, _ps_0 );
    __m128 x_le_0 = _mm_cmple_ps( x, _ps_0 );
    __m128 y_eq_0 = _mm_cmpeq_ps( y, _ps_0 );
    __m128 x_lt_0 = _mm_cmplt_ps( x, _ps_0 );
    __m128 y_lt_0 = _mm_cmplt_ps( y, _ps_0 );

    __m128 zero_mask = _mm_and_ps( x_eq_0, y_eq_0 );
    __m128 zero_mask_other_case = _mm_and_ps( y_eq_0, x_gt_0 );
    zero_mask = _mm_or_ps( zero_mask, zero_mask_other_case );

    __m128 pio2_mask = _mm_andnot_ps( y_eq_0, x_eq_0 );
    __m128 pio2_mask_sign = _mm_and_ps( y_lt_0, _ps_sign_mask );
    __m128 pio2_result = _ps_cephes_PIO2F;
    pio2_result = _mm_xor_ps( pio2_result, pio2_mask_sign );
    pio2_result = _mm_and_ps( pio2_mask, pio2_result );

    __m128 pi_mask = _mm_and_ps( y_eq_0, x_le_0 );
    __m128 pi = _ps_cephes_PIF;
    __m128 pi_result = _mm_and_ps( pi_mask, pi );

    __m128 swap_sign_mask_offset = _mm_and_ps( x_lt_0, y_lt_0 );
    swap_sign_mask_offset = _mm_and_ps( swap_sign_mask_offset, _ps_sign_mask );

    __m128 offset0 = _mm_setzero_ps();
    __m128 offset1 = _ps_cephes_PIF;
    offset1 = _mm_xor_ps( offset1, swap_sign_mask_offset );

    __m128 offset = _mm_andnot_ps( x_lt_0, offset0 );
    offset = _mm_and_ps( x_lt_0, offset1 );

    __m128 arg = _mm_div_ps( y, x );
    __m128 atan_result = atan_ps( arg );
    atan_result = _mm_add_ps( atan_result, offset );

    // Select between zero_result, pio2_result and atan_result

    __m128 result = _mm_andnot_ps( zero_mask, pio2_result );
    atan_result = _mm_andnot_ps( pio2_mask, atan_result );
    atan_result = _mm_andnot_ps( pio2_mask, atan_result);
    result = _mm_or_ps( result, atan_result );
    result = _mm_or_ps( result, pi_result );

    return result;
}

static inline void fast_matmul4x4_sse(float *A, float *B, float *C)
{
    __m128 row1 = _mm_load_ps(&B[0]);                   // Row 0 of B
    __m128 row2 = _mm_load_ps(&B[4]);                   // Row 1 of B
    __m128 row3 = _mm_load_ps(&B[8]);                   // Row 2 of B
    __m128 row4 = _mm_load_ps(&B[12]);                  // Row 3 of B

    for(int i = 0; i < 4; i++)
    {
        __m128 brod1 = _mm_set1_ps(A[4 * i + 0]);       // Example for row 0 computation -> A[0][0] is broadcasted
        __m128 brod2 = _mm_set1_ps(A[4 * i + 1]);       // Example for row 0 computation -> A[0][1] is broadcasted
        __m128 brod3 = _mm_set1_ps(A[4 * i + 2]);       // Example for row 0 computation -> A[0][2] is broadcasted
        __m128 brod4 = _mm_set1_ps(A[4 * i + 3]);       // Example for row 0 computation -> A[0][3] is broadcasted

        __m128 row = _mm_add_ps(                        // Example for row 0 computation -> P + Q
                        _mm_add_ps(                     // Example for row 0 computation -> P = A[0][0] * B[0][0] + A[0][1] * B[1][0]
                            _mm_mul_ps(brod1, row1),    // Example for row 0 computation -> (A[0][0] * B[0][0], A[0][0] * B[0][1], A[0][0] * B[0][2], A[0][0] * B[0][3])
                            _mm_mul_ps(brod2, row2)),   // Example for row 0 computation -> (A[0][1] * B[1][0], A[0][1] * B[1][1], A[0][1] * B[1][2], A[0][1] * B[1][3])
                        _mm_add_ps(                     // Example for row 0 computation -> Q = A[0][2] * B[2][0] + A[0][3] * B[3][0]
                            _mm_mul_ps(brod3, row3),    // Example for row 0 computation -> (A[0][2] * B[2][0], A[0][2] * B[2][1], A[0][2] * B[2][2], A[0][2] * B[2][3])
                            _mm_mul_ps(brod4, row4)));  // Example for row 0 computation -> (A[0][3] * B[3][0], A[0][3] * B[3][1], A[0][3] * B[3][2], A[0][3] * B[3][3])

        _mm_store_ps(&C[4*i], row);                     // Example for row 0 computation -> Storing whole computed row 0
    }
}

#endif //AMD_RPP_RPP_CPU_SIMD_HPP