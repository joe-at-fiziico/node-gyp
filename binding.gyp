{
  "targets": [
    {
      "target_name": "qos",
      "sources": [ "src/qos.cc", "src/async.cc", "src/sync.cc" ],
      "include_dirs": [ 
      	'<!(node -e "require(\'nan\')")',
      	'<!(pwd)/external/include',
      	'<!(pwd)/include'
      ],
      "libraries": [
	  	"<!(pwd)/external/build/libqos.a"
      ]
    }
  ]
}
