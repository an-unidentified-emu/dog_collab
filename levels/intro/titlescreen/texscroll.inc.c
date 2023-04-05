void scroll_titlescreen_Text_mesh_vtx_2() {
	int i = 0;
	int count = 3105;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(titlescreen_Text_mesh_vtx_2);

	deltaX = (int)(1.0 * 0x20) % width;
	deltaY = (int)(1.0 * 0x20) % height;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;	currentY += deltaY;
}

void scroll_sts_mat_titlescreen_electricity_layer1() {
	Gfx *mat = segmented_to_virtual(mat_titlescreen_electricity_layer1);
	shift_s(mat, 10, PACK_TILESIZE(0, 5));
	shift_t_down(mat, 10, PACK_TILESIZE(0, 4));
	shift_s_down(mat, 15, PACK_TILESIZE(0, 3));
	shift_t(mat, 15, PACK_TILESIZE(0, 8));
};

void scroll_intro_level_dl_titlescreen() {
	scroll_titlescreen_Text_mesh_vtx_2();
	scroll_sts_mat_titlescreen_electricity_layer1();
}
