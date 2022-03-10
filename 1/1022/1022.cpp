#include <iostream>
#include <vector>

using namespace std;

struct CUBE
{
    int         id;             //  id
    int         neighbor[8];    //  隣のキューブ
    vector<int> pos;            //  位置
    bool        fixed;          //  位置が確定したか

    CUBE() : fixed(false) {}
};

typedef vector<CUBE>::iterator iter;

int main()
{
    int t;  cin >> t;
    while ( t-- > 0 )
    {
        //  読み込み
        int n;  cin >> n;
        vector<CUBE> cube(n);
        for ( int i=0; i<n; i++ )
        {
            cin >> cube[i].id;
            for ( int j=0; j<8; j++ )
                cin >> cube[i].neighbor[j];
        }

        //  各キューブの位置を決定
        cube[0].pos = vector<int>( 4, 0 );
        cube[0].fixed = true;

        try
        {
            bool update;
            do
            {
                update = false;

                for ( iter c=cube.begin(); c!=cube.end(); c++ )
                if ( c->fixed )
                {
                    for ( int j=0; j<8; j++ )
                    if ( c->neighbor[j] > 0 )
                    {
                        //  neighbor[j]のidを探す
                        iter nb;
                        for ( nb=cube.begin(); nb!=cube.end(); nb++ )
                            if ( nb->id == c->neighbor[j] )
                                break;
                        if ( nb == cube.end()  ||  nb == c )
                            throw 0;

                        //  整合性チェック
                        if ( nb->neighbor[j^1] != c->id )
                            throw 0;

                        //  隣のキューブの位置を求める
                        vector<int> p = c->pos;
                        p[j/2] += j%2*2 - 1;

                        //  既に異なる位置が設定されていたらおかしい
                        if ( nb->fixed  &&  nb->pos != p )
                            throw 0;

                        if ( ! nb->fixed )
                        {
                            nb->pos = p;
                            nb->fixed = true;
                            update = true;
                        }
                    }
                }
            } while ( update );

            //  全てのキューブの位置が確定したチェック
            for ( iter c=cube.begin(); c!=cube.end(); c++ )
                if ( ! c->fixed )
                    throw 0;

            //  各軸の最大最小を求める
            int mn[4] = { 0 };
            int mx[4] = { 0 };

            for ( iter c=cube.begin(); c!=cube.end(); c++ )
                for ( int i=0; i<4; i++ )
                    mn[i] = min( mn[i], c->pos[i] ),
                    mx[i] = max( mx[i], c->pos[i] );

            //  出力
            int box = 1;
            for ( int i=0; i<4; i++ )
                box *= mx[i] - mn[i] + 1;

            cout << box << endl;
        }
        catch ( int )
        {
            cout << "Inconsistent" << endl;
        }
    }

    return 0;
}
