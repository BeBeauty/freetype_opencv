#include <ft2build.h>  
#include FT_FREETYPE_H  

#include <opencv2/opencv.hpp>  

class CvxText
{
	CvxText& operator=(const CvxText&);
public:

	/**
	* װ���ֿ��ļ�
	*/
	CvxText(const char *freeType);
	virtual ~CvxText();

	void getFont(int *type, CvScalar *size = NULL, bool *underline = NULL, float *diaphaneity = NULL);
	void setFont(int *type, CvScalar *size = NULL, bool *underline = NULL, float *diaphaneity = NULL);
	void restoreFont();

	int putText(IplImage *img, const char *text, CvPoint pos);
	int putText(IplImage *img, const wchar_t *text, CvPoint pos);
	int putText(IplImage *img, const char *text, CvPoint pos, CvScalar color);
	int putText(IplImage *img, const wchar_t *text, CvPoint pos, CvScalar color);

private:

	// �����ǰ�ַ�, ����m_posλ��  

	void putWChar(IplImage *img, wchar_t wc, CvPoint &pos, CvScalar color);

private:

	FT_Library   m_library;   // �ֿ�  
	FT_Face      m_face;      // ����  

	int         m_fontType;
	CvScalar   m_fontSize;
	bool      m_fontUnderline;
	float      m_fontDiaphaneity;

};
