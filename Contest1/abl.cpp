#include <iostream>
#include <cmath>


/*class Cell{  
public:
    char v; 					                         // Вертикаль, от 'A' до 'H'
    unsigned short int h;                                // Горизонталь, от '1' до '8'
                        
    Cell(): Cell('A',1) {}	                     // Конструктор клетки по умолчанию
    Cell(char v, unsigned short int h): v(v), h(h) {}	 // Конструктор заданной клетки поля с параметрами
};*/


class Piece{
public:
    Cell cell;
    Piece(Cell cell): cell(cell){}
    Piece(): cell(Cell()){}
    virtual bool available(Cell c) const=0;
};

class Rook: public Piece{
public:
    Rook(Cell c): Piece(c){}
    Rook(): Piece(){}
    bool available(Cell c)  const{
        return ((c.v == cell.v)^(c.h == cell.h));
    }
};

class Bishop:  public Piece{
public:
    Bishop(Cell c): Piece(c){}
    Bishop(): Piece(){}
    bool available(Cell c)  const {
        int a = c.v - cell.v;
        int b = c.h - cell.h;
        return((a == b)^(a == -b));
    }
};

class King: public Piece {
public:
    King(Cell c): Piece(c){}
    bool available(Cell c)  const {
        int a = c.v - cell.v;
        int b = c.h - cell.h;
        if (((a==0)&&(b==0))^((std::abs(a) <= 1)&&(std::abs(b)<= 1))){
            return true;
        }
        else{
            return false;
        }
    }
};

class Queen: public Piece{
public:
    Queen(Cell c): Piece(c){}
    bool available(Cell c) const{
        int a = c.v - cell.v;
        int b = c.h - cell.h;
        return((a == b)^(a == -b))||((c.v == cell.v)^(c.h == cell.h));
    }
};

/*class Queen: public Rook, public Bishop{
public:
    Queen(Cell c): Piece(c), Rook(c), Bishop(c){}
    bool available(Cell c) const{
        //std::cout <<cell.h << " " << cell.v << "\n";
        return this->Rook::available(c)||this->Bishop::available(c);
    }
};*/


/*void are_available(Cell c, const Piece **pieces, bool *availability, std::size_t pieces_count) {
    for (std::size_t piece_idx = 0; piece_idx != pieces_count; ++piece_idx)
        availability[piece_idx] = (pieces[piece_idx])->available(c);
}

int main() {
    const std::size_t size = 4;
    const Piece * pieces[size];
    bool availability[size];

    pieces[0] = new King(Cell('A',1));
    pieces[1] = new Queen(Cell('B',2));
    pieces[2] = new Rook(Cell('C',3));
    pieces[3] = new Bishop(Cell('D',4));

    are_available(Cell('A', 1), pieces, availability, size);
    for(auto ans : availability)
        std::cout << ans << ' ';
    std::cout << std::endl;
    are_available(Cell('B', 2), pieces, availability, size);
    for(auto ans : availability)
        std::cout << ans << ' ';
    std::cout << std::endl;
    are_available(Cell('C', 3), pieces, availability, size);
    for(auto ans : availability)
        std::cout << ans << ' ';
    std::cout << std::endl;
    are_available(Cell('D', 5), pieces, availability, size);
    for(auto ans : availability)
        std::cout << ans << ' ';
    std::cout << std::endl;

    for (auto p : pieces)
        delete p;

    return 0;
}
*/