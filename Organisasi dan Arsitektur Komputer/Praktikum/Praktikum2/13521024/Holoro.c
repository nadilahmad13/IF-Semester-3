void Holoro(input)
{
    int i;
    int num_arr[7];

    read_six_numbers(input, num_arr+1);

    if (num_arr[1] != 1) {
        illegal_move();
    }

    i = 1;
    while(true){
        if (i & 1){
            if (num_arr[i+1] != i * num_arr[i]) goto FLAG;
        }
        else if (num_arr[i+1] != i + num_arr[i]){
    FLAG:
            illegal_move();
        }
        i = i + 1;
        if (i == 6){
            return;
        }
    }
}