{
  "targets": [
    {
      "target_name": "native-idle-time",
      "sources": [ "native-idle-time.cc" ],
      "conditions":[
      	["OS=='linux'", {
      	  "sources": [ "native-idle-time_linux.cc" ],
          "link_settings": {
            "libraries": [
              "-lXss",
              "-lX11"
            ]
          },
      	}],
      	["OS=='mac'", {
      	  "sources": [ "native-idle-time_mac.cc" ],
          "link_settings": {
            "libraries": [
              "-framework", "IOKit"
            ]
          },
      	}],
        ["OS=='win'", {
      	  "sources": [ "native-idle-time_win.cc" ]
      	}]
      ],
      "include_dirs" : [
        "<!(node -e \"require('nan')\")"
      ]
    },
    {
      "target_name": "action_after_build",
      "type": "none",
      "dependencies": [ "<(module_name)" ],
      "copies" : [
        {
          "files": [ "<(PRODUCT_DIR)/<(module_name).node" ],
          "destination": "<(module_path)"
        }
      ]
    }
  ]
}
