struct Shape {
    int shape[4][4][4];
    int id;
    int rot=0;
};

struct Shape T_BLOCK = { { 
    {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0},
        {0}
    },
    {
        {0, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 1, 0, 0},
        {0}
    },
    {
        {0, 0, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {0}
    },
    {
        {0, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 0, 0},
        {0}
    }
}, 1}; 
struct Shape O_BLOCK {
    {
        {
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0},
            {0}
        },
        {
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0},
            {0}
        },
        {
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0},
            {0}
        },
        {
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0},
            {0}
        }
    }, 2
};
struct Shape I_BLOCK { { 
    {
        {0},
        {1, 1, 1, 1},
        {0},
        {0}
    },
    {
        {0, 0, 1},
        {0, 0, 1},
        {0, 0, 1},
        {0, 0, 1}
    },
    {
        {0},
        {0},
        {1, 1, 1, 1},
        {0}
    },
    {
        {0, 1},
        {0, 1, 0, 0},
        {0, 1},
        {0, 1}
    }
}, 3};
struct Shape S_BLOCK = { {
    {
        {0, 1, 1, 0},
        {1, 1, 0, 0},
        {0},
        {0}
    },
    {
        {0, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0}
    },
    {
        {0},
        {0},
        {0, 1, 1, 0},
        {1, 1, 0, 0},
    },
    {
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 0, 0},
        {0}
    }
}, 4};

struct Shape Z_BLOCK = { {
    {
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0},
        {0}
    },
    {
        {0, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 1, 0, 0},
        {0}
    },
    {
        {0},
        {0},
        {1, 1, 0, 0},
        {0, 1, 1, 0},
    },
    {
        {0, 1, 0, 0},
        {1, 1, 0, 0},
        {1, 0, 0, 0},
        {0}
    }
}, 5};

struct Shape L_BLOCK = { {
    {
        {0},
        {0, 0, 1, 0},
        {1, 1, 1, 0},
        {0},
    },
    {
        {0, 1},
        {0, 1},
        {0, 1, 1},
        {0},
    },
    {
        {0},
        {1, 1, 1, 0},
        {1, 0, 0, 0},
        {0},
    },
    {
        {1, 1},
        {0, 1},
        {0, 1},
        {0},
    }
}, 6};
struct Shape J_BLOCK = { {
    {
        {1},
        {1, 1, 1, 0},
        {0},
        {0},
    },
    {
        {0, 1, 1},
        {0, 1},
        {0, 1},
        {0}
    },
    {
        {0},
        {1, 1, 1},
        {0, 0, 1},
        {0}
    },
    {
        {0, 1},
        {0, 1},
        {1, 1},
        {0}
    }
}, 7};

struct Shape SHAPES[7] = {T_BLOCK, I_BLOCK, S_BLOCK, O_BLOCK, Z_BLOCK, L_BLOCK, J_BLOCK};