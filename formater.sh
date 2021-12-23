dir=$(ls -l . | awk '/^d/ {print $NF}')
for i in $dir
do
	echo $i
	file=$(ls $i)
	for filename in $file
	do
		if [[ $filename =~ go ]];then
			gofmt $i/$filename > $i/out
			mv $i/out $i/$filename
			echo $filename
		elif [[ $filename =~ py ]]; then
			black $i/$filename
		fi
	done
	echo ''
done
