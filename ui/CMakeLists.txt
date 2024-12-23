set(requires lvgl)
idf_component_register(
    SRC_DIRS 
    "."
    "./fonts"
    "./images"
    "./screens"

    INCLUDE_DIRS
    "."

    REQUIRES ${requires}

    # EMBED_TXTFILES user_mqtt/ali_iot_ca.crt
    
    WHOLE_ARCHIVE
)