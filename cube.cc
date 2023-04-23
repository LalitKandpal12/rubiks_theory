#include <iostream>
#include <GL/freeglut.h>
const int white = 0;
const int red = 1;
const int blue = 2;
const int green = 3;
const int orange = 4;
const int yellow = 5;

/* Yellow on top 
    Red on front
    Orange on back
    blue on right
    green on left
    White on bottom*/

class cube {
    int cube_box [6][9];
    public:
        cube () {
            for ( int i = 0; i < 6; i++){
                for (  int j = 0; j < 9; j++ ){
                    if (0 == i){
                        cube_box[i][j] = white;
                    }
                    else  if  (1 == i){
                        cube_box[i][j] = red;
                    }
                    else if (2==i){
                        cube_box[i][j] = blue;
                    }
                    else if ( 3 == i){
                        cube_box[i][j] = green;
                    }
                    else if ( 4 == i){
                        cube_box[i][j] = orange;
                    }
                    else  {
                        cube_box[i][j] = yellow;
                    }
                }
            }
        }

        int print_cube  () {
            for ( int i = 0; i < 6; i ++){
                for ( int j = 0; j < 9; j++){
                    std:: cout << cube_box[i][j] << " ";
                }
                std:: cout <<  std:: endl;
            }
            std:: cout <<  std:: endl;
            return 0;
        }

        int cube_rotation ( int series_turing[4], int index[3], int side )  {
            int temp_box[9];
            for (int i = 0; i < 9; i++){
                temp_box[i] = cube_box[side][(i + 3) % 9];
            }
            for (int i  = 0; i<9; i++){
                cube_box[side][i] = temp_box[i];
            }
            int temp [3] = {cube_box [series_turing[0]][index[0]], cube_box [series_turing[0]][index[1]],cube_box [series_turing[0]][index[2]]};
            int new_temp[3];
            for ( int  i = 1; i <= 4; i++){
                new_temp[0] = cube_box[series_turing[i % 4]][index[0]];
                cube_box[series_turing[i % 4]][index[0]] = temp[0];
                temp[0] = new_temp[0];
                new_temp[1] = cube_box[series_turing[i % 4]][index[1]];
                cube_box[series_turing[i % 4]][index[1]] = temp[1];
                temp[1] = new_temp[1];
                new_temp[2] = cube_box[series_turing[i % 4]][index[2]];
                cube_box[series_turing[i % 4]][index[2]] = temp[2];
                temp[2] = new_temp[2];
            }
            return 0;
        }

        int turn (char letter){
            int series_turning[4];
            int index[3];
            int side;
            if ( letter == 'L' || letter == 'R'){
                series_turning[0] =  white;
                series_turning[1] =  orange;
                series_turning[2] = yellow;
                series_turning[3] =  red;
                side = letter == 'L' ? green: blue;
                index[0] = letter == 'L' ? 0 : 2;
                index[1] = letter == 'L' ? 3 : 5;
                index[2] = letter == 'L' ? 6 : 8;
            }
            else if ( letter  == 'D' || letter == 'U'){
                series_turning[0] =  green;
                series_turning[1] =  orange;
                series_turning[2] =  blue;
                series_turning[3] =  red;
                side = letter == 'D' ? white: yellow;
                index[0] = letter == 'D' ? 6 : 0;
                index[1] = letter == 'D' ? 7 : 1;
                index[2] = letter == 'D' ? 8 : 2;
            }
            else if  ( letter == 'F' || letter == 'B'){
                series_turning[0] =  blue;
                series_turning[1] =  white;
                series_turning[2] = green;
                series_turning[3] =  yellow;
                side = letter == 'F' ? red: orange;
                index[0] = letter == 'F' ? 0 : 2;
                index[1] = letter == 'F' ? 3 : 5;
                index[2] = letter == 'F' ? 6 : 8;
            }

            int return_code = cube_rotation(series_turning, index, side);
            return return_code;
        }

        int left_turn () {
            // displacing  green_side
            int green_temp[9];
            for (int i = 0; i < 9; i++){
                green_temp[i] = cube_box[green][(i + 3) % 9];
            }
            for (int i  = 0; i<9; i++){
                cube_box[green][i] = green_temp[i];
            }
            int series_turing[4] = { white,  orange,  yellow, red};
            int temp [3] = {cube_box [series_turing[0]][0], cube_box [series_turing[0]][3],cube_box [series_turing[0]][6]};
            int new_temp[3];
            for ( int  i = 1; i <= 4; i++){
                new_temp[0] = cube_box[series_turing[i % 4]][0];
                cube_box[series_turing[i % 4]][0] = temp[0];
                temp[0] = new_temp[0];
                new_temp[1] = cube_box[series_turing[i % 4]][3];
                cube_box[series_turing[i % 4]][3] = temp[1];
                temp[1] = new_temp[1];
                new_temp[2] = cube_box[series_turing[i % 4]][6];
                cube_box[series_turing[i % 4]][6] = temp[2];
                temp[2] = new_temp[2];
            }
            return 0;
        }

        int right_turn () {
            // displacing  green_side
            int blue_temp[9];
            for (int i = 0; i < 9; i++){
                blue_temp[i] = cube_box[blue][(i + 3) % 9];
            }
            for (int i  = 0; i<9; i++){
                cube_box[blue][i] = blue_temp[i];
            }

            int series_turing[4] = { white,  orange,  yellow, red};
            int temp [3] = {cube_box [series_turing[0]][2], cube_box [series_turing[0]][5],cube_box [series_turing[0]][8]};
            int new_temp[3];
            for ( int  i = 1; i <= 4; i++){
                new_temp[0] = cube_box[series_turing[i % 4]][2];
                cube_box[series_turing[i % 4]][2] = temp[0];
                temp[0] = new_temp[0];
                new_temp[1] = cube_box[series_turing[i % 4]][5];
                cube_box[series_turing[i % 4]][5] = temp[1];
                temp[1] = new_temp[1];
                new_temp[2] = cube_box[series_turing[i % 4]][8];
                cube_box[series_turing[i % 4]][8] = temp[2];
                temp[2] = new_temp[2];
            }
            return 0;
        }
    

};

int main () {
    cube Rubiks;
    Rubiks.print_cube();
    Rubiks.turn('F');
    // Rubiks.right_turn();
    Rubiks.print_cube();
}