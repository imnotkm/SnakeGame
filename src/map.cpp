int map[5][21][21] = {
// stage 1
                    {{2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2}},



// stage 2
                    {{2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,1,1,1,1,1,2,1,1,1,1,1,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2}},



// stage 3
                    {{2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1},
                    {1,0,0,0,1,1,1,2,0,0,0,0,0,2,1,1,1,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,1,1,1,2,0,0,0,0,0,2,1,1,1,0,0,0,1},
                    {1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2}},



//stage 4
                    {{2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1},
                    {1,0,0,0,1,0,0,0,0,0,0,1,2,2,1,0,0,0,0,0,1},
                    {1,0,0,0,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1},
                    {1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1},
                    {1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1},
                    {1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1},
                    {1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1},
                    {1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1},
                    {1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2}},



// stage 5
                    {{2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,1,0,0,0,1,2,1,0,0,0,1,0,0,0,0,1},
                    {1,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1},
                    {1,0,0,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,1},
                    {1,0,0,1,2,1,0,0,0,0,2,0,0,0,0,1,2,1,0,0,1},
                    {1,0,0,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,1},
                    {1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
                    {1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,1,2,1,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2}}

};