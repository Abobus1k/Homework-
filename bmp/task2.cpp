void rotation(int rotate = 180, const char* inpic = "rainbow.bmp", const char* outpic = "wobniar.bmp")
{
	RgbImg in = readRgbImg(inpic);

	if (rotate % 90 != 0)
	{
		std::cout << "Wrong angle!\n";
	}
	else {
		rotate %= 360;
		if (rotate == 90)
		{
			RgbImg out = createRgbImg(in.width, in.height, { 0, 0, 0 });
			for (size_t x = 0; x < in.width; x++)
			{
				for (size_t y = 0; y < in.height; y++)
				{
					out.pixels[in.width - 1 - x][y] = in.pixels[y][x];
				}
			}
			writeRgbImg(outpic, out);
			deleteRgbImg(in);
			deleteRgbImg(out);
		}
		else if (rotate == 180) {
			RgbImg out = createRgbImg(in.height, in.width, { 0, 0, 0 });
			for (size_t x = 0; x < in.width; x++)
			{
				for (size_t y = 0; y < in.height; y++)
				{
					out.pixels[y][x] = in.pixels[in.height - y - 1][in.width - x - 1];
				}
			}
			writeRgbImg(outpic, out);
			deleteRgbImg(in);
			deleteRgbImg(out);
		}
		else if (rotate == 270) {
			RgbImg out = createRgbImg(in.width, in.height, { 0, 0, 0 });
			for (size_t x = 0; x < in.width; x++)
			{
				for (size_t y = 0; y < in.height; y++)
				{
					out.pixels[x][in.height - 1 - y] = in.pixels[y][x];
				}
			}
			writeRgbImg(outpic, out);
			deleteRgbImg(out);
			deleteRgbImg(in);
		}
	}
}
int main(int argc, const char* argv[])
{
	try {
		rotation();
	}
	catch (std::exception const& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return -1;
	}
	return 0;
}
