dir="$(ls -l ./code | awk '/^d/ {print $NF}')"
for i in $dir
do
	if [[ $i == template ]];then
		continue
	fi
	file=$(ls code/$i)
	for filename in $file
	do
		if [[ $filename =~ go ]];then
			gofmt code/$i/$filename > code/$i/out
			mv code/$i/out code/$i/$filename
		elif [[ $filename =~ py ]]; then
			black code/$i/$filename
		elif [[ $filename =~ cpp ]]; then
			clang-format code/$i/$filename > code/$i/out
			mv code/$i/out code/$i/$filename
		elif [[ $filename =~ out ]]; then
			rm code/$i/$filename
		elif [[ $filename =~ swp ]]; then
			rm code/$i/$filename
		fi
	done
done

python gen_readme.py
