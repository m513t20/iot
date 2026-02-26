

String id(){
    //TODO make it from MAC
    return "";
}

void start_AP_mode(){

}

void start_client_mode(){

}

void init_WIFI(bool mode){
    if (mode == WIFI_START_MODE_CLIENT)
        start_client_mode();
    else
        start_AP_mode();
}