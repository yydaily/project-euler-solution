dir=$(ls -l . | awk '/^d/ {print $NF}')
for i in $dir
do
	if [[ $i == template ]];then
		continue
	fi
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
		elif [[ $filename =~ cpp ]]; then
			clang-format $i/$filename > $i/out
			mv $i/out $i/$filename
		elif [[ $filename =~ out ]]; then
			rm $i/$filename
		fi
	done
	echo ''
done

python gen_readme.py
