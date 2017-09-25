/* Simple PSHV Encoder by Rinnegatamante */
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,char** argv){
	
	float framerate = atof(argv[1]);
	
	char* audio_buffer;
	char* video_buffer;

	unsigned long audiosize;
	unsigned long videosize;
	
	printf("Opening audio track...\n");
	FILE* input_audio = fopen("./temp/audiotrack.ogg","rb");		
	unsigned long read_start = 0;
	fseek(input_audio, 0, SEEK_END);
	unsigned long size = (unsigned long)ftell(input_audio);
	audiosize = size - read_start;
	audio_buffer = (char*)malloc(audiosize);
	fseek(input_audio, read_start, SEEK_SET);
	fread(audio_buffer, 1, audiosize, input_audio);
	fclose(input_audio);
	printf("Audio size: %lu bytes\n", size);
	
	printf("Opening video track...\n");
	FILE* input_video = fopen("./temp/baseline.264","rb");		
	read_start = 0;
	fseek(input_video, 0, SEEK_END);
	size = (unsigned long)ftell(input_video);
	videosize = size - read_start;
	video_buffer = (char*)malloc(videosize);
	fseek(input_video, read_start, SEEK_SET);
	fread(video_buffer, 1, videosize, input_video);
	fclose(input_video);
	printf("Video size: %lu bytes\n", size);
	
	printf("Writing output.pshv...\n");
	FILE* output = fopen("output.pshv", "wb");
	fwrite("PSHV",1,4,output);
	fwrite(&framerate, sizeof(float), 1, output);
	fwrite(&audiosize, sizeof(unsigned long), 1, output);
	fwrite(audio_buffer, audiosize, 1, output);
	fwrite(video_buffer, videosize, 1, output);
	fclose(output);
	printf("Done!\n", size);
	
	free(audio_buffer);
	free(video_buffer);
	
	return 0;
	
}