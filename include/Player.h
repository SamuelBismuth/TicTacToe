#ifndef PLAYER_H
#define PLAYER_H


virtual class Player
{
    public:
        Player();
        virtual ~Player();

    protected:

    private:
        virtual const string name() const;
        virtual const Coordinate play(const Board& board);
};

#endif // PLAYER_H
