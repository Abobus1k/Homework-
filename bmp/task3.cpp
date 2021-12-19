void norainbow(const char* name = "rainbow.bmp", const char* outname = "norainbow.bmp")
{
	RgbImg in = readRgbImg(name);
	RgbImg out = createRgbImg(in.height, in.width, { 0,0,0 });
	for (size_t i = 0; i < in.width; ++i)
	{
		for (size_t j = 0; j < in.height; ++j)
		{
			out.pixels[j][i].Blue = (in.pixels[j][i].Blue + in.pixels[j][i].Red + in.pixels[j][i].Green) / 3;
			out.pixels[j][i].Red = (in.pixels[j][i].Blue + in.pixels[j][i].Red + in.pixels[j][i].Green) / 3;
			out.pixels[j][i].Green = (in.pixels[j][i].Blue + in.pixels[j][i].Red + in.pixels[j][i].Green) / 3;
		}
	}
	writeRgbImg(outname, out);
	deleteRgbImg(in);
	deleteRgbImg(out);
}
int main(int argc, const char* argv[])
{
	try {
		norainbow();
	}
	catch (std::exception const& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return -1;
	}
	return 0;
}