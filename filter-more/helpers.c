#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
        for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int colour;
            colour = round((image[i][j].rgbtGreen + image[i][j].rgbtBlue + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtGreen = colour;
            image[i][j].rgbtBlue = colour;
            image[i][j].rgbtRed = colour;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                temp[i][j] = image[i][j];
            }
        }

        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                int total_red, total_blue, total_green;
                total_red = total_blue = total_green = 0;
                float counter = 0;

                for(int x = -1; x < 2; x++)
                {
                    for(int y = -1; y < 2; y++)
                    {
                        int currentx = x + i;
                        int currenty = y + j;

                        if(currentx < 0 || currentx > height - 1 || currenty < 0 || currenty > width -1)
                        {
                            continue;
                        }

                        total_red += image[currentx][currenty].rgbtRed;
                        total_blue += image[currentx][currenty].rgbtBlue;
                        total_green += image[currentx][currenty].rgbtGreen;

                        counter ++;
                    }
                }
                temp[i][j].rgbtRed = round(total_red / counter);
                temp[i][j].rgbtBlue = round(total_blue / counter);
                temp[i][j].rgbtGreen = round(total_green / counter);
            }
        }
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                image[i][j].rgbtRed = temp[i][j].rgbtRed;
                image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
                image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            }
        }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                temp[i][j] = image[i][j];
            }
        }

 for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                int total_red, total_blue, total_green;
                total_red = total_blue = total_green = 0;

                int tota_red, tota_blue, tota_green;
                tota_red = tota_blue = tota_green = 0;


                for(int x = -1; x < 2; x++)
                {
                    for(int y = -1; y < 2; y++)
                    {
                        int currentx = x + i;
                        int currenty = y + j;

                        if(currentx < 0 || currentx > height - 1 || currenty < 0 || currenty > width -1)
                        {
                            continue;
                        }

                        if(x == -1 && y == -1)
                        {
                            total_red += ((image[currentx][currenty].rgbtRed) * -1);
                            total_blue += ((image[currentx][currenty].rgbtBlue) * -1);
                            total_green += ((image[currentx][currenty].rgbtGreen) * -1);

                            tota_red += ((image[currentx][currenty].rgbtRed) * -1);
                            tota_blue += ((image[currentx][currenty].rgbtBlue) * -1);
                            tota_green += ((image[currentx][currenty].rgbtGreen) * -1);
                        }
                        else if(x == -1 && y == 0)
                        {
                            total_red += ((image[currentx][currenty].rgbtRed) * 0);
                            total_blue += ((image[currentx][currenty].rgbtBlue) * 0);
                            total_green += ((image[currentx][currenty].rgbtGreen) * 0);

                            tota_red += ((image[currentx][currenty].rgbtRed) * -2);
                            tota_blue += ((image[currentx][currenty].rgbtBlue) * -2);
                            tota_green += ((image[currentx][currenty].rgbtGreen) * -2);
                        }
                        else if(x == -1 && y == 1)
                        {
                            total_red += ((image[currentx][currenty].rgbtRed) * 1);
                            total_blue += ((image[currentx][currenty].rgbtBlue) * 1);
                            total_green += ((image[currentx][currenty].rgbtGreen) * 1);

                            tota_red += ((image[currentx][currenty].rgbtRed) * -1);
                            tota_blue += ((image[currentx][currenty].rgbtBlue) * -1);
                            tota_green += ((image[currentx][currenty].rgbtGreen) * -1);
                        }

                        else if(x == 0 && y == -1)
                        {
                            total_red += ((image[currentx][currenty].rgbtRed) * -2);
                            total_blue += ((image[currentx][currenty].rgbtBlue) * -2);
                            total_green += ((image[currentx][currenty].rgbtGreen) * -2);

                            tota_red += ((image[currentx][currenty].rgbtRed) * 0);
                            tota_blue += ((image[currentx][currenty].rgbtBlue) * 0);
                            tota_green += ((image[currentx][currenty].rgbtGreen) * 0);
                        }

                        else if(x == 0 && y == 0)
                        {
                            total_red += ((image[currentx][currenty].rgbtRed) * 0);
                            total_blue += ((image[currentx][currenty].rgbtBlue) * 0);
                            total_green += ((image[currentx][currenty].rgbtGreen) * 0);

                            tota_red += ((image[currentx][currenty].rgbtRed) * 0);
                            tota_blue += ((image[currentx][currenty].rgbtBlue) * 0);
                            tota_green += ((image[currentx][currenty].rgbtGreen) * 0);
                        }

                        else if(x == 0 && y == 1)
                        {
                            total_red += ((image[currentx][currenty].rgbtRed) * 2);
                            total_blue += ((image[currentx][currenty].rgbtBlue) * 2);
                            total_green += ((image[currentx][currenty].rgbtGreen) * 2);

                            tota_red += ((image[currentx][currenty].rgbtRed) * 0);
                            tota_blue += ((image[currentx][currenty].rgbtBlue) * 0);
                            tota_green += ((image[currentx][currenty].rgbtGreen) * 0);
                        }

                        else if(x == 1 && y == -1)
                        {
                            total_red += ((image[currentx][currenty].rgbtRed) * -1);
                            total_blue += ((image[currentx][currenty].rgbtBlue) * -1);
                            total_green += ((image[currentx][currenty].rgbtGreen) * -1);

                            tota_red += ((image[currentx][currenty].rgbtRed) * 1);
                            tota_blue += ((image[currentx][currenty].rgbtBlue) * 1);
                            tota_green += ((image[currentx][currenty].rgbtGreen) * 1);
                        }

                        else if(x == 1 && y == 0)
                        {
                            total_red += ((image[currentx][currenty].rgbtRed) * 0);
                            total_blue += ((image[currentx][currenty].rgbtBlue) * 0);
                            total_green += ((image[currentx][currenty].rgbtGreen) * 0);

                            tota_red += ((image[currentx][currenty].rgbtRed) * 2);
                            tota_blue += ((image[currentx][currenty].rgbtBlue) * 2);
                            tota_green += ((image[currentx][currenty].rgbtGreen) * 2);
                        }

                        else if(x == 1 && y == 1)
                        {
                            total_red += ((image[currentx][currenty].rgbtRed) * 1);
                            total_blue += ((image[currentx][currenty].rgbtBlue) * 1);
                            total_green += ((image[currentx][currenty].rgbtGreen) * 1);

                            tota_red += ((image[currentx][currenty].rgbtRed) * 1);
                            tota_blue += ((image[currentx][currenty].rgbtBlue) * 1);
                            tota_green += ((image[currentx][currenty].rgbtGreen) * 1);
                        }
                    }

                float squareRed,squarered,Red;
                squareRed = total_red * total_red;
                squarered = tota_red * tota_red;
                Red = sqrt(squareRed + squarered);
                if(Red > 255)
                {
                    Red = 255;
                }
                temp[i][j].rgbtRed = round(Red);

                float squareBlue,squareblue,Blue;
                squareBlue = total_blue * total_blue;
                squareblue = tota_blue * tota_blue;
                Blue = sqrt(squareBlue + squareblue);
                if(Blue > 255)
                {
                    Blue = 255;
                }
                temp[i][j].rgbtBlue = round(Blue);

                float squareGreen,squaregreen,Green;
                squareGreen = total_green * total_green;
                squaregreen = tota_green * tota_green;
                Green = sqrt(squareGreen + squaregreen);
                if(Green > 255)
                {
                    Green = 255;
                }
                temp[i][j].rgbtGreen = round(Green);

                }
            }
        }
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                image[i][j].rgbtRed = temp[i][j].rgbtRed;
                image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
                image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            }
        }





    return;
}
