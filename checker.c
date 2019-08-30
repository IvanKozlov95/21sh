int main(void)
{
	char		buf[5] = {0};
	read(0, buf, 4);
	printf("%x %x %x %x\n", buf[0], buf[1], buf[2], buf[3]);
	printf("%x\n", *(int *)buf);
}