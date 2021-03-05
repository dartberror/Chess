using namespace std;

class Pawn: public BaseFigure{   ///< ����� �����
 public:
    Pawn(int type0, int x_cell0, int y_cell0) : BaseFigure(type0, x_cell0, y_cell0){}      ///< �����������
    virtual void draw(int x, int y, int r) override{}                                                         ///< ���������
    virtual void count_move_ability_cells(vector<BaseFigure*> figures) override;           ///< ������� ����������� �����
    virtual void change() override{}
};

void Pawn :: count_move_ability_cells(vector<BaseFigure*> figures) {
    if(type == 0) {     // �����
        //int i = y_cell - 1;
        int i = y_cell;
        for(auto figura : figures) {
            if((i - 1 == figura->get_y_cell()) && (x_cell + 1 == figura->get_x_cell())) {     //������ ������� ���������
                int* cell = new int[2];
                cell[0] = i - 1;
                cell[1] = x_cell + 1;
                move_ability_cells.push_back(cell);
            }
            if((i - 1 == figura->get_y_cell()) && (x_cell - 1 == figura->get_x_cell())) {     //����� ������� ���������
                int* cell = new int[2];
                cell[0] = i - 1;
                cell[1] = x_cell - 1;
                move_ability_cells.push_back(cell);
            }
            if((i-1 != figura->get_y_cell()) || (x_cell != figura->get_x_cell())) {             //������ �����
                int* cell = new int[2];
                cell[0] = i-1;
                cell[1] = x_cell;
                move_ability_cells.push_back(cell);
            }
        }
        if(y_cell == 6){
            for(auto figura : figures) {
                if((i - 1 != figura->get_y_cell()) && (x_cell != figura->get_x_cell())) {      //2 ������ �����
                    int* cell = new int[2];
                    cell[0] = i - 2;
                    cell[1] = x_cell;
                    move_ability_cells.push_back(cell);
                }
            }
        }
    }
    if(type == 1) {              // ������
        int i = y_cell;
        for(auto figura : figures) {
            if((i + 1 == figura->get_y_cell()) && (x_cell + 1 == figura->get_x_cell())) {    //������ ������ ���������
                int* cell = new int[2];
                cell[0] = i + 1;
                cell[1] = x_cell + 1;
                move_ability_cells.push_back(cell);
            }
            if((i + 1 == figura->get_y_cell()) && (x_cell - 1 == figura->get_x_cell())) {    //����� ������ ���������
                int* cell = new int[2];
                cell[0] = i + 1;
                cell[1] = x_cell - 1;
                move_ability_cells.push_back(cell);
            }
            if((i != figura->get_y_cell()) && (x_cell != figura->get_x_cell())) {             //������ ����
                int* cell = new int[2];
                cell[0] = i+1;
                cell[1] = x_cell;
                move_ability_cells.push_back(cell);
            }
        }
        if(y_cell == 1){
            for(auto figura : figures) {
                if((i + 1 != figura->get_y_cell()) && (x_cell != figura->get_x_cell())) {    //2 ������ ����
                    int* cell = new int[2];
                    cell[0] = i + 2;
                    cell[1] = x_cell;
                    move_ability_cells.push_back(cell);
                }
            }
        }
    }

}
