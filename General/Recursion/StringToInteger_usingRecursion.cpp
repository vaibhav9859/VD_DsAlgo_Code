int stringToNumber(char input[], int i=0) {
	if(i== strlen(input))  return 0;
    	return stringToNumber(input, i+1) + ( (input[i]-'0') * pow(10, (strlen(input)-i-1) ) );
}