#!/vendor/bin/sh

scriptname=${0##*/}

notice()
{
	echo "$*"
	echo "$scriptname: $*" > /dev/kmsg
}

set_ro_hw_properties_dislayport()
{
	local dp_path=/sys/class/drm/card0-DP-1
	local wait_cnt=0
	while [ "$wait_cnt" -lt 5 ]; do
		if [ -e $dp_path ]; then
			setprop ro.vendor.hw.displayport true
			notice "setprop ro.vendor.hw.displayport as true"
			break;
		fi
		notice "waiting for dp, wait_cnt is $wait_cnt"
		sleep 1;
		wait_cnt=$((wait_cnt+1))
	done
}

# Main starts here
set_ro_hw_properties_dislayport
