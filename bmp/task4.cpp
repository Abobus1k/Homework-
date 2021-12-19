void testBoxFilter()
{
	RgbImg img = readRgbImg("kidsnoise.bmp");
	RgbImg filtered = convolution(img, 5);
	writeRgbImg("nokidsnoise.bmp", filtered);
	deleteRgbImg(img);
	deleteRgbImg(filtered);
}



void preconvolution(const char* name = "nokidsnoise.bmp", const char* out = "rezkost5.bmp")
{
	testBoxFilter();
	RgbImg img = readRgbImg(name);
	size_t krn_sz = 3;
	double** ker = new double* [krn_sz];
	for (int i = 0; i < krn_sz; ++i) ker[i] = new double[3];
	for (int i = 0; i < krn_sz; ++i)
		for (int j = 0; j < krn_sz; ++j)
		{
			std::cin >> ker[i][j];
		}
	writeRgbImg(out, convolution(img, krn_sz, ker));
	deleteRgbImg(img);
	delete[] ker;

}

int main(int argc, const char* argv[])
{
	try {
		preconvolution();
	}
	catch (std::exception const& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return -1;
	}
	return 0;
}