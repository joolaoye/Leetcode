int candy(int* ratings, int ratingsSize){
    int* distro = malloc(sizeof(int) * ratingsSize);

    for (int k = 0; k < ratingsSize; k++){
      distro[k] = 1;
    }

    for (int i = 0; i < ratingsSize; i++){
        if (i > 0 && ratings[i] > ratings[i - 1]){
          distro[i] = (distro[i] > distro[i - 1] + 1) ? distro[i] : distro[i - 1] + 1;
        }
    }

    for (int j = ratingsSize - 1; j > -1; j--){
        if (j < ratingsSize - 1 && ratings[j] > ratings[j + 1]){
            distro[j] = (distro[j] > distro[j + 1] + 1) ? distro[j] : distro[j + 1] + 1;
        }
    }

    int runningsum = 0;

    for (int k = 0; k < ratingsSize; k++){
      runningsum += distro[k];
    }

    free(distro);

    return runningsum;
}