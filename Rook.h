//#include "base_figure.h"


class Rook: public BaseFigure{   ///< ����� �����
 public:
    Rook(int type0, int x_cell0, int y_cell0) : BaseFigure(type0, x_cell0, y_cell0){}      ///< �����������
    virtual void draw(int x, int y, int r) override;                                                          ///< ���������
    virtual void count_move_ability_cells(vector<BaseFigure*> figures) override;               ///< ������� ����������� �����
    virtual void change() override{}
    /*void printArray(){
      cout<<"size="<<move_ability_cells.size()<<'\n';
      for (int i = 0; i < move_ability_cells.size(); i++){
         cout<<"[y"<<i<<"]="<<move_ability_cells[i][0]<<"  ";
         cout<<"[x"<<i<<"]="<<move_ability_cells[i][1]<<'\n';
      }
    } */
};


void Rook :: count_move_ability_cells(vector<BaseFigure*> figures) {
    bool out = false;
    for(int i = y_cell-1; i >= 0; i--) {   ///< �����
        int* cell = new int[2];
        cell[0] = i;
        cell[1] = x_cell;

        move_ability_cells.push_back(cell);

        for(auto figura : figures) {
            if((i == figura->get_y_cell()) && (x_cell == figura->get_x_cell())) {
                   out = true;
                   break;
            }
        }
        if(out){
            break;
        }
    }

    out = false;
    for(int i = y_cell+1; i <= 7; i++) {              ///< ����   (����, � �� ������� � ���������� 8)
        int* cell = new int[2];
        cell[0] = i;
        cell[1] = x_cell;

        move_ability_cells.push_back(cell);

        for(auto figura : figures) {
            if((i == figura->get_y_cell()) && (x_cell == figura->get_x_cell())) {
                   out = true;
                   break;
            }
        }
        if(out){
            break;
        }
    }

    out = false;
    for(int j = x_cell-1; j >= 0; j--) {             ///< �����
        int* cell = new int[2];
        cell[0] = y_cell;
        cell[1] = j;

        move_ability_cells.push_back(cell);

        for(auto figura : figures) {
            if((y_cell == figura->get_y_cell()) && (j == figura->get_x_cell())) {
                   out = true;
                   break;
            }
        }
        if(out){
            break;
        }
    }

    out = false;
    for(int j = x_cell+1; j <= 7; j++) {             ///< ������
        int* cell = new int[2];
        cell[0] = y_cell;
        cell[1] = j;

        move_ability_cells.push_back(cell);

        for(auto figura : figures) {
            if((y_cell == figura->get_y_cell()) && (j == figura->get_x_cell())) {
                   out = true;
                   break;
            }
        }
        if(out){
            break;
        }
    }
}

void Rook::draw (int x, int y, int r)
{
    txSetColor(TX_BLACK,2);
    txSetFillColor (RGB (255, 255, 255));

    POINT head[12] = {{r+x, (9*r)+y}, {r+x, (4*r)+y}, {(3*r)+x, (4*r)+y}, {(3*r)+x, (7*r)+y }, {(4*r)+x, (7*r)+y}, {(4*r)+x,(5*r)+y}, {(7*r)+x,(5*r)+y}, {(7*r)+x,(7*r)+y}, {(8*r)+x,(7*r)+y}, {(8*r)+x,(4*r)+y},{(10*r)+x,(4*r)+y}, {(10*r)+x,(9*r)+y}}; //"������", �������� � ����������� �� ������
    txPolygon (head, 12);

     POINT neck[4] = {{(2*r)+x, (9*r)+y}, {(9*r)+x,(9*r)+y},{(9*r)+x, (10*r)+y},{(2*r)+x,(10*r)+y}};
    txPolygon (neck, 4);

    POINT body[4] = {{(4*r)+x, (10*r)+y}, {(7*r)+x, (10*r)+y}, {(8*r)+x, (20*r)+y}, {(3*r)+x, (20*r)+y}}; //!������������ ����
    txPolygon (body, 4);

    POINT stand1[4] = {{(2*r)+x, (20*r)+y}, {(9*r)+x, (20*r)+y}, {(9*r)+x, (21*r)+y}, {(2*r)+x, (21*r)+y}}; //������ ��������� ��� ����, � � ����� ������ ���
    txPolygon (stand1, 4);

    POINT stand2[4] = {{(1*r)+x, (21*r)+y}, {(10*r)+x, (21*r)+y}, {(10*r)+x, (22*r)+y}, {(1*r)+x, (22*r)+y}}; //������ ��������� ��� �������(�����,����,����) � ������
    txPolygon (stand2, 4);

    //POINT stand3[4] = {{(0*r)+x, (22*r)+y}, {(11*r)+x, (22*r)+y}, {(11*r)+x, (23*r)+y}, {(0*r)+x, (23*r)+y}};//������ ��������� ��� ������(������, �������)
   // txPolygon (stand3, 4);
}
