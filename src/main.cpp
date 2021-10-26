#include <Arduino.h>
#include <LG_Matrix_Print.h>

#define LEDMATRIX_CS_PIN 16
#define USE_PREDEFINED_MATRIX

// Number of 8x8 segments you are connecting
#define LEDMATRIX_SEGMENTS 4

// The LEDMatrixDriver class instance
LG_Matrix_Print lmd(LEDMATRIX_SEGMENTS, LEDMATRIX_CS_PIN, 0);

ushort matrixPositions[16][16] = {
    {
        0x718,
        0x618,
        0x518,
        0x418,
        0x318,
        0x218,
        0x118,
        0x18,
        0x710,
        0x610,
        0x510,
        0x410,
        0x310,
        0x210,
        0x110,
        0x10,
    },
    {
        0x719,
        0x619,
        0x519,
        0x419,
        0x319,
        0x219,
        0x119,
        0x19,
        0x711,
        0x611,
        0x511,
        0x411,
        0x311,
        0x211,
        0x111,
        0x11,
    },
    {
        0x71A,
        0x61A,
        0x51A,
        0x41A,
        0x31A,
        0x21A,
        0x11A,
        0x1A,
        0x712,
        0x612,
        0x512,
        0x412,
        0x312,
        0x212,
        0x112,
        0x12,
    },
    {
        0x71B,
        0x61B,
        0x51B,
        0x41B,
        0x31B,
        0x21B,
        0x11B,
        0x1B,
        0x713,
        0x613,
        0x513,
        0x413,
        0x313,
        0x213,
        0x113,
        0x13,
    },
    {
        0x71C,
        0x61C,
        0x51C,
        0x41C,
        0x31C,
        0x21C,
        0x11C,
        0x1C,
        0x714,
        0x614,
        0x514,
        0x414,
        0x314,
        0x214,
        0x114,
        0x14,
    },
    {
        0x71D,
        0x61D,
        0x51D,
        0x41D,
        0x31D,
        0x21D,
        0x11D,
        0x1D,
        0x715,
        0x615,
        0x515,
        0x415,
        0x315,
        0x215,
        0x115,
        0x15,
    },
    {
        0x71E,
        0x61E,
        0x51E,
        0x41E,
        0x31E,
        0x21E,
        0x11E,
        0x1E,
        0x716,
        0x616,
        0x516,
        0x416,
        0x316,
        0x216,
        0x116,
        0x16,
    },
    {
        0x71F,
        0x61F,
        0x51F,
        0x41F,
        0x31F,
        0x21F,
        0x11F,
        0x1F,
        0x717,
        0x617,
        0x517,
        0x417,
        0x317,
        0x217,
        0x117,
        0x17,
    },
    {
        0xF,
        0x10F,
        0x20F,
        0x30F,
        0x40F,
        0x50F,
        0x60F,
        0x70F,
        0x7,
        0x107,
        0x207,
        0x307,
        0x407,
        0x507,
        0x607,
        0x707,
    },
    {
        0xE,
        0x10E,
        0x20E,
        0x30E,
        0x40E,
        0x50E,
        0x60E,
        0x70E,
        0x6,
        0x106,
        0x206,
        0x306,
        0x406,
        0x506,
        0x606,
        0x706,
    },
    {
        0xD,
        0x10D,
        0x20D,
        0x30D,
        0x40D,
        0x50D,
        0x60D,
        0x70D,
        0x5,
        0x105,
        0x205,
        0x305,
        0x405,
        0x505,
        0x605,
        0x705,
    },
    {
        0xC,
        0x10C,
        0x20C,
        0x30C,
        0x40C,
        0x50C,
        0x60C,
        0x70C,
        0x4,
        0x104,
        0x204,
        0x304,
        0x404,
        0x504,
        0x604,
        0x704,
    },
    {
        0xB,
        0x10B,
        0x20B,
        0x30B,
        0x40B,
        0x50B,
        0x60B,
        0x70B,
        0x3,
        0x103,
        0x203,
        0x303,
        0x403,
        0x503,
        0x603,
        0x703,
    },
    {
        0xA,
        0x10A,
        0x20A,
        0x30A,
        0x40A,
        0x50A,
        0x60A,
        0x70A,
        0x2,
        0x102,
        0x202,
        0x302,
        0x402,
        0x502,
        0x602,
        0x702,
    },
    {
        0x9,
        0x109,
        0x209,
        0x309,
        0x409,
        0x509,
        0x609,
        0x709,
        0x1,
        0x101,
        0x201,
        0x301,
        0x401,
        0x501,
        0x601,
        0x701,
    },
    {
        0x8,
        0x108,
        0x208,
        0x308,
        0x408,
        0x508,
        0x608,
        0x708,
        0x0,
        0x100,
        0x200,
        0x300,
        0x400,
        0x500,
        0x600,
        0x700,
    },
};

void setPixel(byte x, byte y, bool on)
{
  lmd.setPixel(matrixPositions[y & 15][x & 15] & 255, matrixPositions[y & 15][x & 15] / 256, on);
}

void setupInitialMatrix()
{
#ifdef USE_PREDEFINED_MATRIX
  return;
#endif
  for (int x = 0; x < 8; x++)
    for (int y = 0; y < 8; y++)
    {
      // matrix 1
      matrixPositions[y][x] = x + (y * 256);
      // matrix 2
      matrixPositions[y][x + 8] = (x + 8) + (y * 256);
      // matrix 3
      matrixPositions[y + 8][x] = (x + 16) + (y * 256);
      // matrix 4
      matrixPositions[y + 8][x + 8] = (x + 24) + (y * 256);
    }
}

void RotateMatrixX(byte startX, byte startY)
{
  for (int x = startX; x < startX + 8; x++)
  {
    for (int y = startY; y < startY + 8; y++)
    {
      byte newX = (matrixPositions[y][x] & 255) + 8;
      if (newX > 31)
        newX &= 7;
      matrixPositions[y][x] = newX | (matrixPositions[y][x] & 0xff00);
    }
  }
}

void Rotate90(byte startX, byte startY)
{
  ushort a[8][8];
  for (int x = 0; x < 8; x++)
    for (int y = 0; y < 8; y++)
      a[x][y] = matrixPositions[y + startY][x + startX];

  int N = 8;
  for (int i = 0; i < N / 2; i++)
  {
    for (int j = i; j < N - i - 1; j++)
    {

      ushort temp = a[i][j];
      a[i][j] = a[N - 1 - j][i];
      a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
      a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
      a[j][N - 1 - i] = temp;
    }
  }

  for (int x = 0; x < 8; x++)
    for (int y = 0; y < 8; y++)
      matrixPositions[y + startY][x + startX] = a[x][y];
}

void MirrorX(byte startX, byte startY)
{
  ushort a[8][8];
  for (int x = 0; x < 8; x++)
    for (int y = 0; y < 8; y++)
      a[y][x] = matrixPositions[y + startY][x + startX];

  int N = 8;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N / 2; j++)
    {

      ushort temp = a[i][j];
      a[i][j] = a[i][7 - j];
      a[i][7 - j] = temp;
    }
  }

  for (int x = 0; x < 8; x++)
    for (int y = 0; y < 8; y++)
      matrixPositions[y + startY][x + startX] = a[y][x];
}

void setup()
{
  setupInitialMatrix();
  Serial.begin(115200);
  lmd.setEnabled(true);
  lmd.setIntensity(0); // 0 = low, 15 = high
  lmd.clear();
  lmd.display();
}

void loop()
{
  Serial.println("16x16 LED Matrix Setup");
  Serial.println("");
  Serial.println("1) Adjusting matrix order");
  String input = "n";
  while (input != "y")
  {

    lmd.clear();
    setPixel(4, 4, true);
    lmd.display();
    Serial.println("Does one LED light up in the UPPER LEFT quarter of the matrix? ['y' or 'n']");
    do
    {
      input = Serial.readString();
    } while (input == "");
    if (input != "y")
      RotateMatrixX(0, 0);
  }

  input = "n";
  while (input != "y")
  {

    lmd.clear();
    setPixel(12, 4, true);
    lmd.display();
    Serial.println("Does one LED light up in the UPPER RIGHT quarter of the matrix? ['y' or 'n']");
    do
    {
      input = Serial.readString();
    } while (input == "");
    if (input != "y")
      RotateMatrixX(8, 0);
  }

  input = "n";
  while (input != "y")
  {

    lmd.clear();
    setPixel(4, 12, true);
    lmd.display();
    Serial.println("Does one LED light up in the LOWER LEFT quarter of the matrix? ['y' or 'n']");
    do
    {
      input = Serial.readString();
    } while (input == "");
    if (input != "y")
      RotateMatrixX(0, 8);
  }

  input = "n";
  while (input != "y")
  {

    lmd.clear();
    setPixel(12, 12, true);
    lmd.display();
    Serial.println("Does one LED light up in the LOWER RIGHT quarter of the matrix? ['y' or 'n']");
    do
    {
      input = Serial.readString();
    } while (input == "");
    if (input != "y")
      RotateMatrixX(8, 8);
  }

  input = "n";
  while (input != "y")
  {

    lmd.clear();
    for (int i = 0; i < 8; i++)
      setPixel(i, 0, true);
    lmd.display();
    Serial.println("Do you see a horizontal line on TOP of the UPPER LEFT quarter of the matrix? ['y' or 'n']");
    do
    {
      input = Serial.readString();
    } while (input == "");
    if (input != "y")
      Rotate90(0, 0);
  }

  input = "n";
  while (input != "y")
  {

    lmd.clear();
    for (int i = 0; i < 8; i++)
      setPixel(i + 8, 0, true);
    lmd.display();
    Serial.println("Do you see a horizontal line on TOP of the UPPER RIGHT quarter of the matrix? ['y' or 'n']");
    do
    {
      input = Serial.readString();
    } while (input == "");
    if (input != "y")
      Rotate90(8, 0);
  }

  input = "n";
  while (input != "y")
  {

    lmd.clear();
    for (int i = 0; i < 8; i++)
      setPixel(i, 8, true);
    lmd.display();
    Serial.println("Do you see a horizontal line on TOP of the LOWER LEFT quarter of the matrix? ['y' or 'n']");
    do
    {
      input = Serial.readString();
    } while (input == "");
    if (input != "y")
      Rotate90(0, 8);
  }

  input = "n";
  while (input != "y")
  {

    lmd.clear();
    for (int i = 0; i < 8; i++)
      setPixel(i + 8, 8, true);
    lmd.display();
    Serial.println("Do you see a horizontal line on TOP of the LOWER RIGHT quarter of the matrix? ['y' or 'n']");
    do
    {
      input = Serial.readString();
    } while (input == "");
    if (input != "y")
      Rotate90(8, 8);
  }

  input = "n";
  while (input != "y")
  {

    lmd.clear();
    for (int i = 0; i < 8; i++)
      setPixel(0, i, true);
    lmd.display();
    Serial.println("Do you see a vertical line on the LEFT side of the UPPER LEFT quarter of the matrix? ['y' or 'n']");
    do
    {
      input = Serial.readString();
    } while (input == "");
    if (input != "y")
      MirrorX(0, 0);
  }

  input = "n";
  while (input != "y")
  {

    lmd.clear();
    for (int i = 0; i < 8; i++)
      setPixel(8, i, true);
    lmd.display();
    Serial.println("Do you see a vertical line on the LEFT side of the UPPER RIGHT quarter of the matrix? ['y' or 'n']");
    do
    {
      input = Serial.readString();
    } while (input == "");
    if (input != "y")
      MirrorX(8, 0);
  }

  input = "n";
  while (input != "y")
  {

    lmd.clear();
    for (int i = 0; i < 8; i++)
      setPixel(0, i + 8, true);
    lmd.display();
    Serial.println("Do you see a vertical line on the LEFT side of the LOWER LEFT quarter of the matrix? ['y' or 'n']");
    do
    {
      input = Serial.readString();
    } while (input == "");
    if (input != "y")
      MirrorX(0, 8);
  }

  input = "n";
  while (input != "y")
  {

    lmd.clear();
    for (int i = 0; i < 8; i++)
      setPixel(8, i + 8, true);
    lmd.display();
    Serial.println("Do you see a vertical line on the LEFT side of the LOWER RIGHT quarter of the matrix? ['y' or 'n']");
    do
    {
      input = Serial.readString();
    } while (input == "");
    if (input != "y")
      MirrorX(8, 8);
  }

  Serial.println("Please watch the matrix. One LED after the other, column by column and row by row should");
  Serial.println("light up until the whole matrix is lit.");
  lmd.clear();
  for (int row = 0; row < 16; row++)
    for (int col = 0; col < 16; col++)
    {
      setPixel(col, row, true);
      lmd.display();
      delay(30);
    }
  Serial.println("Did the LEDs on the matrix light up in the correct order? ['y' or 'n']");
  do
  {
    input = Serial.readString();
  } while (input == "");
  if (input == "y")
  {
    Serial.println("Please copy the following code into the *Matrix Setup* section of the main source file:");
    Serial.println("");
    Serial.println("// Matrix Setup - START");
    Serial.println("ushort _matrix[16][16] = {");
    for (int row = 0; row < 16; row++)
    {
      Serial.println("  {");
      Serial.print("    ");
      for (int col = 0; col < 16; col++)
      {
        Serial.print("0x");
        Serial.print(matrixPositions[row][col], 16);
        Serial.print(", ");
      }
      Serial.println("  },");
    }
    Serial.println("};");
    Serial.println("// Matrix Setup - END");
  }
}