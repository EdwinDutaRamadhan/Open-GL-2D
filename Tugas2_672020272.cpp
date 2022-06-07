#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
int r = 300;//jari-jari matahari
int merahmatahari = 1.0;
int hijauMatahari = 0.5;
int biruMatahari = 0.25;
int a = 9;//balue pengurang jari-jari matahari
int j = 0;
void init() {
    
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_BLEND);         //Tugas2
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    gluOrtho2D(0.0, 1280, 0.0, 720);
    /*
    glClearColor(1, 1, 1, 0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glPointSize(10.0);
    glLoadIdentity();
    glLineWidth(4.0f);
    gluOrtho2D(0.0, 720.0, 0.0, 480.0);
    */
}
void perpotongangaris() {
    float   ax = 50,
            ay = 50,
            bx = 200,
            by = 350,
            cx = 125,
            cy = 100,
            dx = 25,
            dy = 300,
            ex = 90,
            ey = 250,
            fx = 400,
            fy = 300,
            Mab, Mcd, Mef, Cab, Ccd, Cef, px, py, pz, pi;

    glClear(GL_COLOR_BUFFER_BIT);

    //Garis merah
    glBegin(GL_LINES);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex2f(ax,ay);
    glVertex2f(bx,by);
    glEnd();

    //Garis biru
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(cx,cy);
    glVertex2f(dx,dy);
    glEnd();

    //Garis hijau
    glBegin(GL_LINES);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(ex,ey);
    glVertex2f(fx,fy);
    glEnd();

    //Perpotongan Garis
    Mab = (by - ay) / (bx - ax);
    Mcd = (dy - cy) / (dx - cx);
    Mef = (fy - ey) / (fx - ex);
    Cab = ay - (ax * Mab);
    Ccd = cy - (cx * Mcd);
    Cef = ey - (ex * Mef);

    //Titik Potong
    px = (Ccd - Cab) / (Mab - Mcd);
    py = (Mab * px) + Cab;
    pz = (Cef - Cab) / (Mab - Mef);
    pi = (Mef * pz) + Cef;

    //Hasil Perpotongan Garis
    glBegin(GL_POINTS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(px, py);
    glEnd();

    glBegin(GL_POINTS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(pz, pi);
    glEnd();

    glFlush();
}

void lingkaran(int sisi, int x, int y) {
    /*if (j == 1) {
        glBegin(GL_POLYGON);
    }*/
    glBegin(GL_POLYGON);
    for (int i = 0; i < sisi; i++) {
        glVertex2f((r * cos(2 * 3.14159265 * i / sisi)) + x, (r * sin(2 * 3.14159265 * i / sisi)) + y);
    }
    glEnd();
}


void objek() {
    glClear(GL_COLOR_BUFFER_BIT);
    //Canvas
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2f(0,0);
    glVertex2f(1280,0);
    glVertex2f(1280,720);
    glVertex2f(0,720);
    glEnd();

    //langitAtasGradasi
    glBegin(GL_QUADS);
    glColor3f(1, 1, 0.6);
    glVertex2f(0, 600);
    glVertex2f(1280, 600);
    glVertex2f(1280, 720);
    glVertex2f(0, 720);
    glEnd();

    //gradasiLangitAtasLagitTengah
    glBegin(GL_QUADS);
    glColor3f(1, 1, 0.6);
    glVertex2f(0, 600);
    glVertex2f(1280, 600); glColor3f(0.8, 1, 1);
    glVertex2f(1280, 720);
    glVertex2f(0, 720);
    glEnd();


    //langitBelakangBukit
    glBegin(GL_QUADS);
    glColor3f(1, 1, 0.6);
    glVertex2f(0, 200);
    glVertex2f(1280, 200);
    glVertex2f(1280, 400);
    glVertex2f(0, 400);
    glEnd();

    //shadowLangitBelakangBukit
    glBegin(GL_QUADS);
    glColor3f(1, 0.6, 0.4);
    glVertex2f(0, 200);
    glVertex2f(1280, 200); glColor3f(1, 1, 0.6);
    glVertex2f(1280, 400);
    glVertex2f(0, 400);
    glEnd();

    //langitTengah
    glBegin(GL_QUADS);
    glColor3f(1, 1, 0.6);
    glVertex2f(0, 400);
    glVertex2f(1280, 400);
    glVertex2f(1280, 600);
    glVertex2f(0, 600);
    glEnd();

    /*
    for (j = 0; j < 10; j++) {
        glColor3f(merahmatahari, hijauMatahari, biruMatahari);
        lingkaran(360, 640, 200);
        r = r - 5;
        hijauMatahari = hijauMatahari + 0.04;
        biruMatahari = biruMatahari + 0.02;
    }
    */
    //Jangan Klik Output Console Program(Window output program)
    //CPU dan ram tersiksa
    
    //Matahari
        glColor3f(1.0, 0.5, 0.25);
        lingkaran(360, 640, 200);r = r - a;
        glColor3f(1.0, 0.53, 0.27);
        lingkaran(360, 640, 200);r = r - a;
        glColor3f(1.0, 0.56, 0.29);
        lingkaran(360, 640, 200);r = r - a;
        glColor3f(1.0, 0.59, 0.31);
        lingkaran(360, 640, 200);r = r - a;
        glColor3f(1.0, 0.62, 0.33);
        lingkaran(360, 640, 200);r = r - a;
        glColor3f(1.0, 0.65, 0.35);
        lingkaran(360, 640, 200);r = r - a;
        glColor3f(1.0, 0.68, 0.37);
        lingkaran(360, 640, 200);r = r - a;
        glColor3f(1.0, 0.71, 0.39);
        lingkaran(360, 640, 200);r = r - a;
        glColor3f(1.0, 0.74, 0.41);
        lingkaran(360, 640, 200);r = r - a;
        glColor3f(1.0, 0.77, 0.43);
        lingkaran(360, 640, 200);r = r - a;
        glColor3f(1.0, 0.80, 0.46);
        lingkaran(360, 640, 200);r = r - a;
        glColor3f(1.0, 0.83, 0.49);
        lingkaran(360, 640, 200);r = r - a;
        glColor3f(1.0, 0.86, 0.51);
        lingkaran(360, 640, 200);r = r - a;
        glColor3f(1.0, 0.89, 0.53);
        lingkaran(360, 640, 200);r = r - a;
        glColor3f(1.0, 0.92, 0.55);
        lingkaran(360, 640, 200);r = r - a;
        glColor3f(1.0, 0.95, 0.57);
        lingkaran(360, 640, 200);

    //Laut
    glBegin(GL_QUADS);
    glColor3f(1, 1, 0.6);
    glVertex2f(0, 0);glVertex2f(1280, 0);
    glVertex2f(1280, 200);glVertex2f(0, 200);
    glEnd();

    //ShadowLaut
    glBegin(GL_QUADS);
    glColor3f(0.4, 1, 1);
    glVertex2f(0, 0); 
    glVertex2f(1280, 0); glColor3f(1, 1, 0.6);
    glVertex2f(1280, 200); glVertex2f(0, 200); 
    glEnd();

    //midLane
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2f(0, 198);glVertex2f(1280, 198);
    glEnd();

    //bukitKiriPolygon
    glBegin(GL_POLYGON);glColor3f(0, 0, 0);
    glVertex2f(0, 200);
    glVertex2f(400, 200);glVertex2f(390, 214);
    glVertex2f(380, 223);glVertex2f(370, 232);
    glVertex2f(360, 240);glVertex2f(350, 252);
    glVertex2f(340, 225);glVertex2f(330, 241);
    glVertex2f(320, 280);glVertex2f(200, 320);
    glVertex2f(160, 400);glVertex2f(80, 440);
    glVertex2f(0, 400);
    glEnd();

    //pohonKelapa
        //batangPohon
        glBegin(GL_POLYGON);
        glColor3f(0.2, 0.1, 0);
        glVertex2f(750, 200);glVertex2f(690, 280);
        glVertex2f(700, 280);glVertex2f(760, 200);
        glEnd();
        //kepalaBatangPohon
        glBegin(GL_POLYGON);
        glColor3f(0.1, 0.2, 0);
        glVertex2f(690, 280);glVertex2f(685, 290);
        glVertex2f(695, 290);glVertex2f(700, 280);
        glEnd();
        //daunBatang1
        glBegin(GL_POLYGON);
        glColor3f(0.1, 0.2, 0);
        glVertex2f(690, 280); glVertex2f(685, 290);glVertex2f(675, 277);glVertex2f(680, 272); 
        glEnd();
            //ujungDaunBatang1
            glBegin(GL_TRIANGLES);
            glColor3f(0.1, 0.2, 0);
            glVertex2f(680, 272);glVertex2f(675, 277);glVertex2f(670, 257);
            glEnd();
        //daunBatang2
        glBegin(GL_POLYGON);
        glColor3f(0.1, 0.2, 0);
        glVertex2f(685, 285); glVertex2f(690, 295);
        glVertex2f(670,292);glVertex2f(670, 287);
        glEnd();
            //ujungDaunBatang2
            glBegin(GL_TRIANGLES);
            glColor3f(0.1, 0.2, 0);
            glVertex2f(670, 292);glVertex2f(670, 287);glVertex2f(652, 282);
            glEnd();

        //daunBatang3
        glBegin(GL_POLYGON);
        glColor3f(0.1, 0.2, 0);
        glVertex2f(685, 285);glVertex2f(695, 290);
        glVertex2f(685, 302);glVertex2f(680, 297);    
        glEnd();
            //ujungDaunBatang3
            glBegin(GL_TRIANGLES);
            glColor3f(0.1, 0.2, 0);
            glVertex2f(685, 302);glVertex2f(680, 297);glVertex2f(670, 310);
            glEnd();

        //daunBatang4
        glBegin(GL_POLYGON);
        glColor3f(0.1, 0.2, 0);
        glVertex2f(685, 285);glVertex2f(695, 290);
        glVertex2f(697, 302);glVertex2f(692, 307);
        glEnd();
            //ujungDaunBatang4
            glBegin(GL_TRIANGLES);
            glColor3f(0.1, 0.2, 0);
            glVertex2f(697, 302);glVertex2f(692, 307);glVertex2f(710, 312);
            glEnd();
        //daunBatang5
        glBegin(GL_POLYGON);
        glColor3f(0.1, 0.2, 0);
        glVertex2f(692, 292);glVertex2f(697, 282);
        glVertex2f(702, 287);glVertex2f(702, 297);
        glEnd();
            //ujungDaunBatang5
            glBegin(GL_TRIANGLES);
            glColor3f(0.1, 0.2, 0);
            glVertex2f(702, 287);glVertex2f(702, 297);glVertex2f(722, 290);
            glEnd();
    //bukitKananPolygon
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(700, 200);glVertex2f(720, 210);
    glVertex2f(800, 230);glVertex2f(850, 240);
    glVertex2f(930, 255);glVertex2f(1060, 240);
    glVertex2f(1100, 300);glVertex2f(1100, 200);
    glEnd();

    //bukitKananPolygon
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);   
    glVertex2f(1150, 280);glVertex2f(1130, 295);
    glVertex2f(1100, 300);glVertex2f(1100, 200);
    glVertex2f(1150, 200);glVertex2f(1150, 300);
    glEnd();

    //bukitKananPolygon
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2f(1150, 200);glVertex2f(1150, 280);
    glVertex2f(1180, 250);glVertex2f(1260, 250);
    glVertex2f(1280, 280);glVertex2f(1280, 200);
    glEnd();

    glFlush();
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1280, 720);//Tugas2
    //glutInitWindowSize(720, 480);//Perpotongan
    glutCreateWindow("Tugas 1 | Grafika Komputer H | EdwinDutaRamadhan_672020272");
    init(); 
    glutDisplayFunc(objek);
    //glutDisplayFunc(perpotongangaris);
    //glutFullScreen();
    glutMainLoop();
}
