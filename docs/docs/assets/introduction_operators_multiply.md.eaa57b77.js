import{_ as n,c as s,o as a,d as p}from"./app.2ed2a9a6.js";const d='{"title":"Multiply","description":"","frontmatter":{},"headers":[],"relativePath":"introduction/operators/multiply.md","lastUpdated":1651606220000}',e={},t=p(`<h1 id="multiply" tabindex="-1">Multiply <a class="header-anchor" href="#multiply" aria-hidden="true">#</a></h1><p>The value of the scalar (a in the example) will be multiplied with every component of the 2D vector (b in the example):</p><div class="language-cpp line-numbers-mode"><pre><code>vecmath<span class="token operator">&gt;</span> a<span class="token operator">=</span><span class="token number">3.0</span>
vecmath<span class="token operator">&gt;</span> b<span class="token operator">=</span><span class="token punctuation">[</span><span class="token number">3.1</span><span class="token punctuation">,</span><span class="token number">4.1</span><span class="token punctuation">]</span>
vecmath<span class="token operator">&gt;</span> c<span class="token operator">=</span>a<span class="token operator">*</span>b
vecmath<span class="token operator">&gt;</span> printAll
</code></pre><div class="line-numbers-wrapper"><span class="line-number">1</span><br><span class="line-number">2</span><br><span class="line-number">3</span><br><span class="line-number">4</span><br></div></div><p>The result is :</p><div class="language-cpp line-numbers-mode"><pre><code>a <span class="token operator">=</span> <span class="token punctuation">[</span><span class="token number">3</span><span class="token punctuation">]</span>
b <span class="token operator">=</span> <span class="token punctuation">[</span><span class="token number">3.1</span><span class="token punctuation">,</span><span class="token number">4.1</span><span class="token punctuation">]</span>
c <span class="token operator">=</span> <span class="token punctuation">[</span><span class="token number">9.3</span><span class="token punctuation">,</span><span class="token number">12.3</span><span class="token punctuation">]</span>
</code></pre><div class="line-numbers-wrapper"><span class="line-number">1</span><br><span class="line-number">2</span><br><span class="line-number">3</span><br></div></div><p>Multiplying a 2d vector to a 3d vector means that the z-component of the 2d vector will be set to zero, as a 2d vector can be seen to be a 3d vector on the XY-plane. Remark that multiplication here is not the same as the dot product!</p><div class="language-cpp line-numbers-mode"><pre><code>vecmath<span class="token operator">&gt;</span> a <span class="token operator">=</span> <span class="token punctuation">[</span><span class="token number">4.2</span><span class="token punctuation">,</span><span class="token number">8.3</span><span class="token punctuation">,</span><span class="token operator">-</span><span class="token number">5</span><span class="token punctuation">]</span>
vecmath<span class="token operator">&gt;</span> b <span class="token operator">=</span> <span class="token punctuation">[</span><span class="token number">3.1</span><span class="token punctuation">,</span><span class="token number">4.1</span><span class="token punctuation">]</span>
vecmath<span class="token operator">&gt;</span> c <span class="token operator">=</span> a <span class="token operator">*</span> b
vecmath<span class="token operator">&gt;</span> printAll
</code></pre><div class="line-numbers-wrapper"><span class="line-number">1</span><br><span class="line-number">2</span><br><span class="line-number">3</span><br><span class="line-number">4</span><br></div></div><p>The result is :</p><div class="language-cpp line-numbers-mode"><pre><code>a <span class="token operator">=</span> <span class="token punctuation">[</span><span class="token number">4.2</span><span class="token punctuation">,</span><span class="token number">8.3</span><span class="token punctuation">,</span><span class="token operator">-</span><span class="token number">5</span><span class="token punctuation">]</span>
b <span class="token operator">=</span> <span class="token punctuation">[</span><span class="token number">3.1</span><span class="token punctuation">,</span><span class="token number">4.1</span><span class="token punctuation">]</span>
c <span class="token operator">=</span> <span class="token punctuation">[</span><span class="token number">13.02</span><span class="token punctuation">,</span><span class="token number">34.03</span><span class="token punctuation">,</span><span class="token operator">-</span><span class="token number">0</span><span class="token punctuation">]</span>
</code></pre><div class="line-numbers-wrapper"><span class="line-number">1</span><br><span class="line-number">2</span><br><span class="line-number">3</span><br></div></div><p>The multiplication of two quaternions could be used to more easily implement the axis-angle formula,by storing the axis information in one quaternion, and the pure rotation in the other quaternion:</p><div class="language-cpp line-numbers-mode"><pre><code>vecmath<span class="token operator">&gt;</span> qaxis<span class="token operator">=</span> <span class="token punctuation">[</span><span class="token number">1</span><span class="token punctuation">,</span><span class="token punctuation">(</span><span class="token number">0</span><span class="token punctuation">,</span><span class="token number">0</span><span class="token punctuation">,</span><span class="token number">1</span><span class="token punctuation">)</span><span class="token punctuation">]</span>
vecmath<span class="token operator">&gt;</span> qangle <span class="token operator">=</span> <span class="token punctuation">[</span><span class="token number">0.707</span><span class="token punctuation">,</span><span class="token punctuation">(</span><span class="token number">0.707</span><span class="token punctuation">,</span><span class="token number">0.707</span><span class="token punctuation">,</span><span class="token number">0.707</span><span class="token punctuation">]</span><span class="token punctuation">]</span>
vecmath<span class="token operator">&gt;</span> q <span class="token operator">=</span> qangle<span class="token operator">*</span>qaxis
vecmath<span class="token operator">&gt;</span> print q
</code></pre><div class="line-numbers-wrapper"><span class="line-number">1</span><br><span class="line-number">2</span><br><span class="line-number">3</span><br><span class="line-number">4</span><br></div></div><p>The result is :</p><div class="language-cpp line-numbers-mode"><pre><code>q <span class="token operator">=</span> <span class="token punctuation">[</span><span class="token number">0.707</span> <span class="token punctuation">,</span><span class="token punctuation">(</span> <span class="token number">0</span> <span class="token punctuation">,</span> <span class="token number">0</span> <span class="token punctuation">,</span> <span class="token number">0.707</span> <span class="token punctuation">)</span><span class="token punctuation">]</span>
</code></pre><div class="line-numbers-wrapper"><span class="line-number">1</span><br></div></div><div class="danger custom-block"><p class="custom-block-title">WARNING</p><p>Be very careful with the multiplication. Within the vecmath REPL shell this is always a component wise multiplication and not to be confused with the dot product or complex multiplication.</p></div>`,14),o=[t];function c(l,r,u,i,k,m){return a(),s("div",null,o)}var h=n(e,[["render",c]]);export{d as __pageData,h as default};
