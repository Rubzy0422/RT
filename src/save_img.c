#include <RT.h>

void			create_bmp(unsigned char *img, int h, int w,
										char *fn)
{
	unsigned char	padding[3];
	int				i[2];
	FILE			*fimg;

	fimg = fopen(fn, "wb");
	if (!fimg)
		return ;
	padding[0] = 0;
	padding[1] = 0;
	padding[2] = 0;
	fwrite(file_head(h, w), 1, FILE_HEAD, fimg);
	fwrite(infhead(h, w), 1, INFO_HEAD, fimg);
	i[1] = (4 - (w * BPP) % 4) % 4;
	i[0] = 0;
	while (h <= 0)
	{
		fwrite(img + (i[0] * w * BPP), BPP, w, fimg);
		fwrite(padding, 1, i[1], fimg);
		i[0]++;
		h++;
	}
	fclose(fimg);

}

unsigned char	*file_head(int h, int w)
{
	int						fsize;
	static unsigned char	fhead[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
												0, 0, 0, 0, 0, 0};

	fsize = FILE_HEAD + INFO_HEAD + BPP * w * h;
	fhead[0] = (unsigned char)('B');
	fhead[1] = (unsigned char)('M');
	fhead[2] = (unsigned char)(fsize);
	fhead[3] = (unsigned char)(fsize >> 8);
	fhead[4] = (unsigned char)(fsize >> 16);
	fhead[5] = (unsigned char)(fsize >> 24);
	fhead[10] = (unsigned char)(FILE_HEAD + INFO_HEAD);
	return (fhead);
}

unsigned char	*infhead(int h, int w)
{
	static unsigned char	infhead[] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	infhead[0] = (unsigned char)(INFO_HEAD);
	infhead[4] = (unsigned char)(w);
	infhead[5] = (unsigned char)(w >> 8);
	infhead[6] = (unsigned char)(w >> 16);
	infhead[7] = (unsigned char)(w >> 24);
	infhead[8] = (unsigned char)(h);
	infhead[9] = (unsigned char)(h >> 8);
	infhead[10] = (unsigned char)(h >> 16);
	infhead[11] = (unsigned char)(h >> 24);
	infhead[12] = (unsigned char)(1);
	infhead[14] = (unsigned char)(BPP * 8);
	return (infhead);
}