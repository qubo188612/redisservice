#ifndef _DATA_STRUCTURE_H_
#define _DATA_STRUCTURE_H_

// ���ã�ͨ�����ݽṹ
// ���ߣ�chong.xiao
// ʱ�䣺2024.11.5

#define Sy_CV_CN_MAX     512
#define Sy_CV_CN_SHIFT   3
#define Sy_CV_DEPTH_MAX  (1 << Sy_CV_CN_SHIFT)

#define Sy_CV_8U   0
#define Sy_CV_8S   1
#define Sy_CV_16U  2
#define Sy_CV_16S  3
#define Sy_CV_32S  4
#define Sy_CV_32F  5
#define Sy_CV_64F  6
#define Sy_CV_16F  7

#define Sy_CV_MAT_DEPTH_MASK       (Sy_CV_DEPTH_MAX - 1)
#define Sy_CV_MAT_DEPTH(flags)     ((flags) & Sy_CV_MAT_DEPTH_MASK)

#define Sy_CV_MAKETYPE(depth,cn) (Sy_CV_MAT_DEPTH(depth) + (((cn)-1) << Sy_CV_CN_SHIFT))
#define Sy_CV_MAKE_TYPE Sy_CV_MAKETYPE

#define Sy_CV_8UC1 Sy_CV_MAKETYPE(Sy_CV_8U,1)
#define Sy_CV_8UC2 Sy_CV_MAKETYPE(Sy_CV_8U,2)
#define Sy_CV_8UC3 Sy_CV_MAKETYPE(Sy_CV_8U,3)
#define Sy_CV_8UC4 Sy_CV_MAKETYPE(Sy_CV_8U,4)
#define Sy_CV_8UC(n) Sy_CV_MAKETYPE(Sy_CV_8U,(n))

#define Sy_CV_8SC1 Sy_CV_MAKETYPE(Sy_CV_8S,1)
#define Sy_CV_8SC2 Sy_CV_MAKETYPE(Sy_CV_8S,2)
#define Sy_CV_8SC3 Sy_CV_MAKETYPE(Sy_CV_8S,3)
#define Sy_CV_8SC4 Sy_CV_MAKETYPE(Sy_CV_8S,4)
#define Sy_CV_8SC(n) Sy_CV_MAKETYPE(Sy_CV_8S,(n))

#define Sy_CV_16UC1 Sy_CV_MAKETYPE(Sy_CV_16U,1)
#define Sy_CV_16UC2 Sy_CV_MAKETYPE(Sy_CV_16U,2)
#define Sy_CV_16UC3 Sy_CV_MAKETYPE(Sy_CV_16U,3)
#define Sy_CV_16UC4 Sy_CV_MAKETYPE(Sy_CV_16U,4)
#define Sy_CV_16UC(n) Sy_CV_MAKETYPE(Sy_CV_16U,(n))

#define Sy_CV_16SC1 Sy_CV_MAKETYPE(Sy_CV_16S,1)
#define Sy_CV_16SC2 Sy_CV_MAKETYPE(Sy_CV_16S,2)
#define Sy_CV_16SC3 Sy_CV_MAKETYPE(Sy_CV_16S,3)
#define Sy_CV_16SC4 Sy_CV_MAKETYPE(Sy_CV_16S,4)
#define Sy_CV_16SC(n) Sy_CV_MAKETYPE(Sy_CV_16S,(n))

#define Sy_CV_32SC1 Sy_CV_MAKETYPE(Sy_CV_32S,1)
#define Sy_CV_32SC2 Sy_CV_MAKETYPE(Sy_CV_32S,2)
#define Sy_CV_32SC3 Sy_CV_MAKETYPE(Sy_CV_32S,3)
#define Sy_CV_32SC4 Sy_CV_MAKETYPE(Sy_CV_32S,4)
#define Sy_CV_32SC(n) Sy_CV_MAKETYPE(Sy_CV_32S,(n))

#define Sy_CV_32FC1 Sy_CV_MAKETYPE(Sy_CV_32F,1)
#define Sy_CV_32FC2 Sy_CV_MAKETYPE(Sy_CV_32F,2)
#define Sy_CV_32FC3 Sy_CV_MAKETYPE(Sy_CV_32F,3)
#define Sy_CV_32FC4 Sy_CV_MAKETYPE(Sy_CV_32F,4)
#define Sy_CV_32FC(n) Sy_CV_MAKETYPE(Sy_CV_32F,(n))

#define Sy_CV_64FC1 Sy_CV_MAKETYPE(Sy_CV_64F,1)
#define Sy_CV_64FC2 Sy_CV_MAKETYPE(Sy_CV_64F,2)
#define Sy_CV_64FC3 Sy_CV_MAKETYPE(Sy_CV_64F,3)
#define Sy_CV_64FC4 Sy_CV_MAKETYPE(Sy_CV_64F,4)
#define Sy_CV_64FC(n) Sy_CV_MAKETYPE(Sy_CV_64F,(n))

#define Sy_CV_16FC1 Sy_CV_MAKETYPE(Sy_CV_16F,1)
#define Sy_CV_16FC2 Sy_CV_MAKETYPE(Sy_CV_16F,2)
#define Sy_CV_16FC3 Sy_CV_MAKETYPE(Sy_CV_16F,3)
#define Sy_CV_16FC4 Sy_CV_MAKETYPE(Sy_CV_16F,4)
#define Sy_CV_16FC(n) Sy_CV_MAKETYPE(Sy_CV_16F,(n))

//��ɫת����־
enum SyColorConversionCodes {

	Sy_COLOR_NOCHANGE = -1, //ͼ�񲻸ı�

	Sy_COLOR_BGR2RGB = 4,

	Sy_COLOR_RGB2BGR = Sy_COLOR_BGR2RGB,

	Sy_COLOR_BGR2GRAY = 6,

	Sy_COLOR_RGB2GRAY = 7,

	Sy_COLOR_GRAY2BGR = 8,

	Sy_COLOR_GRAY2RGB = Sy_COLOR_GRAY2BGR,

	Sy_COLOR_BGR2HSV = 40,

	Sy_COLOR_RGB2HSV = 41,

	Sy_COLOR_BGR2Lab = 44,

	Sy_COLOR_RGB2Lab = 45,

	Sy_COLOR_BGR2HLS = 52,

	Sy_COLOR_RGB2HLS = 53,

	Sy_COLOR_HSV2BGR = 54,

	Sy_COLOR_HSV2RGB = 55,

	Sy_COLOR_Lab2BGR = 56,

	Sy_COLOR_Lab2RGB = 57,

	Sy_COLOR_Luv2BGR = 58,

	Sy_COLOR_Luv2RGB = 59,

	Sy_COLOR_HLS2BGR = 60,

	Sy_COLOR_HLS2RGB = 61,
};
// ��ά��
typedef struct {
	float x; // ���x����
	float y; // ���y����
	float z; // ���z����
} SyPoint3D;

// ��ά��
typedef struct {
	float x; // ���x����
	float y; // ���y����
} SyPoint2D;

// �߶�
typedef struct {
	SyPoint2D start; // �߶ε����
	SyPoint2D end;   // �߶ε��յ�
} LineSegment;

// Բ
typedef struct {
	SyPoint2D center; // Բ�ĵ�
	float radius; // Բ�İ뾶
} SyCircle;

// ����
typedef struct {
	SyPoint2D topLeft; // ���ε����Ͻǵ�
	SyPoint2D bottomRight; // ���ε����½ǵ�
} SyRectangle;

// ͼ��
struct SyImage {
	int	width; // ͼ��Ŀ��
	int	height; // ͼ��ĸ߶�
	int type;//ͼ����������
	unsigned char* data; // ָ��ͼ�����ݵ�ָ�루���磬�������ݣ�
	size_t step = 0;//����ͼ����ռ���ֽ���
} ;

#endif // !
