int g_x{ 2 }; // non-constant globals are external by default (no need to use extern)

// because const and constexpr are internal by default, use extern to give identifiers external linkage.
extern const int g_y{ 3 }; // const globals can be defined as extern, making them external
extern constexpr int g_z{ 3 }; // constexpr globals can be defined as extern, making them external (but this is pretty useless, see the warning in the next section)

extern int g_x;       // this extern is a forward declaration of a variable named g_x that is defined somewhere else

int main()
{
    return 0;
}

/*
To use these extern const and extern constexpr in other files, you must 
    use a forward declaration in another file using the extern keyword as well...
*/